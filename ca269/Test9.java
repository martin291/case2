public class Test
{
    // Add a static print method to this class
    public static void print(Student [] student)
    {
        for(int i = 0; i < student.length; i++)
            System.out.println(student[i].getMark() + " " +  "("+student[i].getName()+")");
    }
}
