class Dog extends Animal
{
    String name;
    
    public Dog(String name)
    {
        super(name);
    }
    
    String hello()
    {
        return "Woof";
    }
}
