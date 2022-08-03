public class Test
{
    // Add a static printForties method to this class.
    public static void printForties(Student [] student)
    {
        for(int i = 0; i < student.length; i++)
        {
            if(student[i].getMark() > 39 && student[i].getMark() < 50)
            {
                System.out.println(student[i].getMark() + " " +  "("+student[i].getName()+")");
            }
        }
    }
}
