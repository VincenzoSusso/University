package esercizio1;

public abstract class FiguraComp implements Figura, Comparable {

    //------------------------------------------
    protected double dim1;
    protected double dim2;
    //------------------------------------------

    public FiguraComp(double dim1, double dim2)
    {
        this.setDim1(dim1);
        this.setDim2(dim2);
    }

    public void setDim1(double dim1) {
        this.dim1 = dim1;
    }

    public double getDim1() {
        return dim1;
    }

    public void setDim2(double dim2) {
        this.dim2 = dim2;
    }

    public double getDim2() {
        return dim2;
    }

    public int compareTo(Object o)
    {
        int response = 0;

        if(this.area() > ((FiguraComp)o).area())
        {
            response = 1;
        }
        else if(this.area() < ((FiguraComp)o).area())
        {
            response = -1;
        }

        return  response;
    }

    public boolean equals(FiguraComp o)
    {
        boolean response = false;

        if(this.compareTo(o) == 0)
        {
            response = true;
        }

        return response;
    }

    //------------------------------------------
    public abstract double area();
}
