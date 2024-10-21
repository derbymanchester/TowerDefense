#include <iostream>
#include <vector>
#include <math.h>
#define pi = 3.141592653589793

using namespace std;

class Tower {
    private:
        float x, y;
        int damage;
        float range;
        float fireRate;
        float DelayTime; // thoi gian doi cho dot ban ke tiep
        float Tower_head; // huong cua dau sung (tien cho viec xoay thap)
    public:
        void checkTypeTower(int type); // Kiem tra loai thap de xay dung thap moi
        Enemy *findNearestEnemy(std::vector<Enemy>& enemies); // Enemy la ten goi class ke dich( xac dinh toa do gan nhat cua dich can ban)
        void shootAt(Enemy* enemy);  // tinh toan duong dan tu vi tri dich gan nhat
        float TurnAroundToEnemy(Enemy* enemy); // xoay thap theo huong cua dich
        void DelayTimeToShoot(float CurrentTime) // tinh toan thoi gian nghi giua cac dot ban
        float getX();
        float getY();
        float getRange();
        int getDamage();
}
