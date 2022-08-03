public class Test
{
    // Add a static getBestSTudent method to this class. It should return a Student object.
    public static Student getBestStudent(Student [] student)
    {
        Student best = student[1];
        for(int i = 0; i < student.length - 1; i++)
        {
            if(student[i + 1].getMark() > best.getMark())
            {
                best = student[i + 1];
            }
        }
        return best;
    }
}
