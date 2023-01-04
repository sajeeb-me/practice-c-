#include<bits/stdc++.h>
using namespace std;

class Cuboid
{
private:
    int length;
    int width;
    int height;

public:
    Cuboid()
    {

    }
    Cuboid(int l, int w, int h)
    {
        length = l;
        width = w;
        height = h;
    }
    int getVolume()
    {
        return length*width*height;
    }
    int getSurfaceArea()
    {
        return (2*length*width)+(2*length*height)+(2*height*width);
    }
    void print_info()
    {
        cout << "length: " << length << " " << "width: " << width << " " << "height: " << height << "\n";
    }
};

bool sortByVol(Cuboid a, Cuboid b)
{
    int aVol = a.getVolume();
    int bVol = b.getVolume();
    return aVol < bVol;
}

bool sortBySurface(Cuboid a, Cuboid b)
{
    int aSurface = a.getSurfaceArea();
    int bSurface = b.getSurfaceArea();
    return aSurface < bSurface;
}

int main()
{
    vector<Cuboid>c(5);
    for(int i=0; i<c.size(); i++)
        c[i]=Cuboid(10+i,10-i,6-i);

    for(int i=0; i<c.size(); i++)
    {
        int vol = c[i].getVolume();
        cout << "vol: " << vol << "\n";

        int surface = c[i].getSurfaceArea();
        cout << "surface: " << surface << "\n";
    }

    sort(c.begin(), c.end(), sortByVol);

    cout << "After sorting by volume: \n";
    for(int i=0; i<c.size(); i++)
    {
        int vol = c[i].getVolume();
        cout << "vol: " << vol << "\n";
    }

    sort(c.begin(), c.end(), sortBySurface);

    cout << "After sorting by surface: \n";
    for(int i=0; i<c.size(); i++)
    {
        int surface = c[i].getSurfaceArea();
        cout << "surface: " << surface << "\n";
    }

    return 0;
}
