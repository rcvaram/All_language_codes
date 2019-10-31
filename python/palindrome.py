def isPalindrome(s): 
     
    rev = s[::-1]
    # Checking if both string are equal or not 
    if (s == rev): 
        return True
    return False

print(isPalindrome("abcdcba"))