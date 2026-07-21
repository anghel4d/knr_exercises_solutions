#include "bulletsentity.h"

#include <stdio.h>
#include <malloc.h>

// Systems
int setAllBulletVelocities(Bullet *bullets, int numBullets, int velocity) {
    for(int i = 0; i < numBullets; i++) {
        bullets[i].velocity = velocity;
    }

    return 1;
}

int setAllBulletMass(Bullet *bullets, int numBullets, int mass) {
    for(int i = 0; i < numBullets; i++) {
        bullets[i].mass = mass;
    }

    return 1;
}

int updateBulletPositions(Bullet *bullets, int numBullets) {
    for(int i = 0; i < numBullets; i++) {
        bullets[i].position += bullets[i].velocity;
    }

    return 1;
}

int main() {
    // Initializing the collection of bullets.
    // We want 100'000
    #define NUM_ENTITIES 100000
    Bullet *bullets = malloc(NUM_ENTITIES * sizeof(Bullet));

    // Setup
    setAllBulletVelocities(bullets, NUM_ENTITIES, 10);
    setAllBulletMass(bullets, NUM_ENTITIES, 10);

    // Main Game Loop
    while(1) {
        updateBulletPositions(bullets, NUM_ENTITIES);

        for(int i = 0; i < NUM_ENTITIES; i++) {
            printf("Damage dealt by bullet: %d\n", bullets[i].mass * bullets[i].velocity);
        }

        break;
    }

    free(bullets);

    return 0;
}