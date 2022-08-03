// A Pig is an animal which has a name and says "Oink".
// It likes to polymorph in an array.
class Pig extends Animal
{
    String name;
    
    public Pig(String name)
    {
        super(name);
    }
    
    String hello()
    {
        return "Oink";
    }
}
