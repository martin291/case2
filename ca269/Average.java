public class Average
{
    public static double averageArea(Shape [] shapes)
    {
        double sum = 0;
        double count = 0;
        for(Shape shape : shapes)
        {
            sum = sum + shape.area();
            count = count + 1;
        }
        
        double average = (sum / count);
        return average;
    }
}
