You can contribute any programs whic can worthy

The Zuma game (another dp problem)

/*Think about Zuma Game. You have a row of balls on the table, colored red(R), yellow(Y), blue(B), green(G), and white(W). You also have several balls in your hand.

Each time, you may choose a ball in your hand, and insert it into the row (including the leftmost place and rightmost place). Then, if there is a group of 3 or more balls in the same color touching, remove these balls. Keep doing this until no more balls can be removed.

Find the minimal balls you have to insert to remove all the balls on the table. If you cannot remove all the balls, output -1.

Examples:

Input: "WRRBBW", "RB"
Output: -1
Explanation: WRRBBW -> WRR[R]BBW -> WBBW -> WBB[B]W -> WW

Input: "WWRRBBWW", "WRBRW"
Output: 2
Explanation: WWRRBBWW -> WWRR[R]BBWW -> WWBBWW -> WWBB[B]WW -> WWWW -> empty

Input:"G", "GGGGG"
Output: 2
Explanation: G -> G[G] -> GG[G] -> empty 

Input: "RBYYBBRRB", "YRBGB"
Output: 3
Explanation: RBYYBBRRB -> RBYY[Y]BBRRB -> RBBBRRB -> RRRB -> B -> B[B] -> BB[B] -> empty 

Note:
You may assume that the initial row of balls on the table won’t have any 3 or more consecutive balls with the same color.
The number of balls on the table won't exceed 20, and the string represents these balls is called "board" in the input.
The number of balls in your hand won't exceed 5, and the string represents these balls is called "hand" in the input.
Both input strings will be non-empty and only contain characters 'R','Y','B','G','W'.

*/


int findMinStep(string board, string hand) {
        if(board.size() == 0) return 0;
        int res = hand.size()+1;
        for(int i = 0; i < board.size(); ) {
            int cur_steps = 0, cnt = 0;
            char ball = board[i];
            // try eliminate current ball
            while(i < board.size() && board[i] == ball) {
                i++;
                cnt++;
            }
            // insert 3-cnt balls, remove it from hand
            if(count(hand.begin(), hand.end(), ball) >= 3-cnt){
                cur_steps += 3-cnt;
                string newhand = hand;
                string left = board.substr(0, i-cnt);
                string right = board.substr(i);
                string newboard = generate(left, right);
                // remove used balls
                for(int k = 0; k < 3-cnt; k++) {
                    newhand.erase(newhand.find(ball), 1);
                }
                int furtherSteps = findMinStep(newboard, newhand);
                if(furtherSteps != -1) {        
                    res = min(res, cur_steps+furtherSteps);
                }                
            }
        }
        return res == hand.size()+1 ? -1 : res;
    }
    // generate new board from left and right
    string generate(string left, string right) {
        int j = left.size()-1, k = 0, dup = 0;
        while(j >= 0 && left[j] == right.front()) { j--; dup++; }
        while(k < right.size() && right[k] == left.back()) { k++;dup++; }
        if(dup >= 3) return generate(left.substr(0, j+1), right.substr(k));
        else return left+right;
    }
