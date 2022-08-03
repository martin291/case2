public class Test
{
    // Add a static printHonours method to this class.
    public static void printHonours(Student [] student)
    {
        for(int i = 0; i < student.length; i++)
        {
            if(student[i].getMark() >= 55)
            {
                System.out.println(student[i].getMark() + " " +  "("+student[i].getName()+")");
            }
        }
    }
}
