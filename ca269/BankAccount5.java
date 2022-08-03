public class BankAccount
{
    double balance = 100;
    public void withdraw(double n)
    {
        balance = balance - n;
    }
    public void deposit(double n)
    {
        balance = balance + n;
    }
    public String toString()
    {
        return ("The balance is "+balance);
    }
}
