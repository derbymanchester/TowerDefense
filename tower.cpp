#include "Tower.h"

void Tower::checkTypeTower(int type, float x, float y)
{
    // Tieu chinh cac loai chi so cua cac loai thap
    const int Type1_dmg = 10;
    const int Type2_dmg = 20;
    const int Type3_dmg = 50;
    const float Type1_fireRate = 10;
    const float Type2_fireRate = 10;
    const float Type3_fireRate = 5;
    const float Type1_range = 1;
    const float Type2_range = 2;
    const float Type3_range = 0.5;
    const float Type1_delay = 0.1;
    const float Type2_delay = 0.1;
    const float Type3_delay = 1;

    // xet thap dang xay la thap loai nao
    if (type == 1) Tower(x, y, Type1_dmg, Type1_range, Type1_fireRate, Type1_delay, 0);
    if (type == 2) Tower(x, y, Type2_dmg, Type2_range, Type2_fireRate, Type2_delay, 0);
    if (type == 3) Tower(x, y, Type3_dmg, Type3_range, Type3_fireRate, Type3_delay, 0);
    return;
}
Tower::Tower(float x_pos, float y_pos, int dmg, float rng, float rate, float delay, float head) // Khoi tao gia tri cho thap
    : x(x_pos), y(y_pos), damage(dmg), range(rng), fireRate(rate), DelayTime(delay), Tower_head(head) {}

Enemy* Tower::findNearestEnemy(vector<Enemy>& enemies) {
    Enemy* nearestEnemy = nullptr;
    float minDistance = 1e9;

    for (auto& enemy : enemies) {
        // duong dan tu thap den ke dich bang can( x * x + y * y) voi (x = xthap - xdich; y = ythap - ydich)
        float distance = sqrt((x - enemy.x) * (x - enemy.x) + (y - enemy.y) * (y - enemy.y));
        if (distance <= range && distance < minDistance) { // neu khoang cach dich nam trong tam ban va nho hon ke dich truoc do thi chon
            minDistance = distance;
            nearestEnemy = &enemy;
        }
    }

    return nearestEnemy;
}

void Tower::shootAt(Enemy* enemy) {
    if (enemy != nullptr) {
        enemy->health -= damage; // giam mau ke dich
    }
}

float Tower::TurnAroundToEnemy(Enemy* enemy) {
    if (enemy != nullptr) {
        float dx = enemy->x - x;
        float dy = enemy->y - y;
        return Tower_head + atan2(dy, dx) * 180 / pi;  // Trả về goc quay thap
    }
    return 0; // tra ve 0 xem nhu khong co ke dich vi dich trung voi thap (nhung vi tri thap nam ngoai vi tri spawn cua dich)
}

void Tower::DelayTimeToShoot(float CurrentTime)
{
    return CurrentTime + DelayTime; // Tra ve thoi gian hien tai + thoi gian delay
}

float Tower::getX() { return x; }
float Tower::getY() { return y; }
float Tower::getRange() { return range; }
int Tower::getDamage() { return damage; }
