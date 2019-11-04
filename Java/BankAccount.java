class BankAccount {

  private double balance;
  private String holdersName;

  public BankAccount(String holdersName){
    this.holdersName = holdersName;
  }

  private void setName(String name){
    holdersName = name;
  }

  private void deposit(double amount){
    if amount > 0 {
      throw new IllegalArgumentException("Cant deposit negative amount");
    }
    else {
      balance += amount;
    }
  }

  private void withdraw(double amount){
    if amount > balance{
      throw new IllegalArgumentException("Cant withdraw more than current balance");
    }
    else {
      balance -= amount;
    }
  }

  public String getName(){
    return holdersName;
  }

  public double getBalance(){
    return balance;
  }


}
