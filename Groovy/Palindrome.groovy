isPalindrome = {a->  s=a as String
i=0;j=s.size()-1
while (j-i>1){
if (s.charAt(i) != s.charAt(j)) return false
i++;j--
}
return true
}


#assert isPalindrome(121)
#assert !isPalindrome(122)
