import static java.lang.Math.PI;

public class Circle extends Shape
{
    private double radius; // radius
    
    public Circle(String s, double r)
    {
        super(s);
        radius = r;
    }
    
    double area()
    {
        double result = ((radius * radius) * Math.PI);
        return result;
    }
}

/*
public class Rectangle extends Shape
{
   private double width, height; // name inherited

   public Rectangle(String s, double w, double h)
   {
      super(s); // use Shape constructor; effect is name=s;
      width = w;
      height = h;
   }

   double area()
   {
      return width * height;
   }
}

public class Triangle extends Shape
{
   private double a, b, c; // lengths of sides

   public Triangle(String s, double x, double y, double z)
   {
      super(s);
      a = x; b = y; c = z;
   }

   double area()
   {
      double s = (a+b+c)/2.0;
      return Math.sqrt(s*(s-a)*(s-b)*(s-c));
   }
}
*/
