public class BankAccount
{
    double balance;
    public BankAccount(double n)
    {
        balance = n;
    }
    public void withdraw(double n)
    {
        balance = balance - n;
    }
}
