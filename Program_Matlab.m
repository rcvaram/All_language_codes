%Matlab Code Prints Hello World 'n' Times

n = input('Enter a number:');
for sentence = 1:n  % have the indexing go from 1 to n, not reverse
    fprintf('%d. Hello world!\n', sentence); % print the index, and a newline \n
end
