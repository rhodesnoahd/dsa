#include <iostream>
#include <string>
using std::string;

class GameEntry {
  public:
    GameEntry(const string& n="", int s=0)
      : name(n), score(s) {};
    string getName() const { return name; }
    int getScore() const { return score; }
  private:
    string name;
    int score;
};

class Scores {
  public:
    Scores(int maxEnt = 10)
      : maxEntries(maxEnt), 
        numEntries(0), 
        entries(new GameEntry[maxEntries]) {};
        
    ~Scores() { delete[] entries;}

    void add(const GameEntry& e) {
      int newScore = e.getScore();
      if (numEntries == maxEntries) {
        int lowScore = entries[numEntries - 1].getScore();
        if (newScore <= lowScore) {
          return;
        }
      }
      numEntries++; // add empty elem
      int i = numEntries - 2; // start second to last
      while (i >= 0 && newScore > entries[i].getScore()) {
        entries[i+1] = entries[i]; // shift right
        i--; // r->l
      }
      entries[i+1] = e; // put e in empty spot
    };

    void remove(int i) {
      if (i < 0 || i > numEntries - 1) {
        return;
      }
      for (int j=i; j < numEntries - 1; j++) {
        entries[j] = entries[j+1];
      }
      numEntries--;
    };

    void printScores() {
      if (!numEntries) std::cout << "[]";
      for (int i=0; i<numEntries; i++) {
        if (i == 0) std::cout << "[";
        std::cout << entries[i].getScore();
        if (i == numEntries - 1) std::cout << "]";
        else std::cout << ", ";
      }
      std::cout << std::endl;
    }

  private:
    int maxEntries;
    int numEntries;
    GameEntry* entries;
};

int main() {
  Scores scores = Scores();

  GameEntry e1 = GameEntry("Noah", 84);
  scores.add(e1);
  GameEntry e2 = GameEntry("Harrison", 96);
  scores.add(e2);
  GameEntry e3 = GameEntry("Alex", 75);
  scores.add(e3);

  scores.printScores(); // [96, 84, 75]

  scores.remove(2); 

  scores.printScores(); // [96, 84]
  
  scores.remove(0); 

  scores.printScores(); // [84]
  
  scores.remove(0); 

  scores.printScores(); // []
}