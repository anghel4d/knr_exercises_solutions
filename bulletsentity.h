// Entity+Components (Simplified)
typedef struct {
    int velocity;
    int position;
    int mass;
} Bullet;

// System Interfaces
int setAllBulletVelocities(Bullet *bullets, int numBullets, int velocity);

int setAllBulletMass(Bullet *bullets, int numBullets, int mass);

int updateBulletPositions(Bullet *bullets, int numBullets);