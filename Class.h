#ifndef CLASS_H
#define CLASS_H

class Latm
{ // Lifting and transport machine //
private:
    int x, y, z, x1, y1, z1; // x1 y1 координаты груза
    float MassaBox;          // масса груза
    float MaxMassa;          // грузоподъемность
    char *TypeLatm;
    int height;
    bool LatmTake = false;

public:
    Latm()
    {
    }

    Latm(char *TypeLatmT, float MaxMassaM, int heightH, int CordX, int CordY, float MassaBoxM, int CordX1, int CordY1);
    Latm(const Latm &a); // не использовал еще
    void destructor();
    void SetX(int CordX);
    void SetY(int CordY);
    void SetZ(int CordZ);
    void inputLatm(char *TypeLatmT, float MaxMassaM, int heightH, int CordX, int CordY, int CordZ, float MassaBoxM, int CordX1, int CordY1, int CordZ1);
    void SetTypeLatm(char *TypeLatmT);
    void SetX1(int CordX);
    void SetY1(int CordY);
    void SetZ1(int CordZ);
    void LatmTravel(int x2, int y2);
    void LatmToBox();
    int GetX() const;
    int GetY() const;
    int GetZ() const;
    int GetMassaBox() const;
    int GetMaxMassa() const;
    char *GetTypeLatm() const;
    int GetX1() const;
    int GetY1() const;
    int GetZ1() const;
    int GetHeight() const;
    void InfoLatm() const;
    void InfoBox() const;
    void Take();
    void Up(int heightH);
    void Down(int heightH);
    void Put();
    bool Proverka()const;
};
#endif