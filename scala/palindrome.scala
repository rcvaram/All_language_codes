object PalindromeCheck {
  def main(args: Array[String]): Unit = {
    println(isPalindrome("abcdcba"))
  }

  def isPalindrome(string:String):Boolean={
      string==string.reverse
  }
  
}
