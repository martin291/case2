public class Test
{
    // Add a static getPassingAverage method to this class. It should return a double value
    //  representing the average makr of passing students
    public static double getPassingAverage(Student [] student)
    {
        int count = 0;
        double sum = 0;
        for(int i = 0; i < student.length; i++)
        {
            if(student[i].getMark() > 39)
            {
                count++;
                sum = sum + student[i].getMark();
            }
        }
        return (sum / count);
    }
}
