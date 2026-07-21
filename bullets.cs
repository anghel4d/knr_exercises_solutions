using System.Collections.Generic;
using System.Linq;

class Bullet {
    public int velocity {get; set;} // 4 bytes
    public int position {get; set;} // 4 bytes

    public Bullet(int velocity, int position) { // 4 bytes
        this.velocity = velocity;
        this.position = position;
    }

    public void UpdatePosition() { // 4 bytes
        this.position = this.position + this.velocity;
    }

    public int CalculateDamage() { // 4 bytes
        return this.velocity * 10;
    }
}

class LargeCaliberBullet : Bullet {
    override public int CalculateDamage() {
        return this.velocity * 50;
    }
}

public class Main {
    public static void Main(string[] args) {
        List<Bullet> bullets = new List<Bullet>();

        // Setup
        for (int i = 0; i < 50000; i++) {
            Bullet bullet = new Bullet(0, 0);
            bullets.Add(bullet);
        }

        for (int i = 0; i < 50000; i++) {
            Bullet bullet = new LargeCaliberBullet(0, 0);
            bullets.Add(bullet);
        }

        // LINQ-powered shuffle
        numbers = bullets.OrderBy(x => Guid.NewGuid()).ToList();

        // Setup
        foreach(Bullet bullet in bullets) {
            bullet.velocity = 10;
        }

        // Main game loop
        while (true) {
            // Bullet 
            foreach(Bullet bullet in bullets) {
                bullet.UpdatePosition();
                Console.WriteLine("Damage dealt by bullet: " + bullet.CalculateDamage() + "");
            }

            break;
        }
        
    }
}