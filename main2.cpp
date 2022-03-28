#include <iostream>
#include <utility>

using namespace std;

class Card {
private:
    int image;
    string type;
    bool taken = false;

public:
    void set_type(string val)
    {
        type = move(val);
    }

    string get_type()
    {
        return type;
    }

    void set_taken() {
        taken = true;
    }
};

class Game_logic {
private:
    Card matrix[3][4]; // Only 4 in memory
    string possible_vals[12];
    string ordered_array[12];
    int p1_points = 0;
    int p2_points = 0;

public:
    Game_logic() {
        Card* c1;
        Card* c2;
        Card* c3;
        Card* c4;

        c1 = new Card;
        c2 = new Card;
        c3 = new Card;
        c4 = new Card;

        matrix[0][0] = *c1;
        matrix[0][1] = *c2;
        matrix[0][2] = *c3;
        matrix[1][0] = *c4;
    }

    void shuffler() { // Creates an array of pairs and arranges them in a random order
        string types_array[4] = {"sun", "bucket", "clover", "skull"};
        int i = 0;
        int k = 0;
        string a;
        int sun = 0;
        int bucket = 0;
        int clover = 0;
        int skull = 0;

        while (i < 11) {
            possible_vals[i] = types_array[k];
            possible_vals[i + 1] = types_array[k];
            i += 2;
            k++;

            if (k == 4) {
                k = 0;
            }
        }

        i = 0;

        while (i < 12) {
            int randn = rand() % 12;
            if (possible_vals[randn] == "sun" && sun < 4) {
                ordered_array[i] = possible_vals[randn];
                sun++;
                i++;
            } else if (possible_vals[randn] == "bucket" && bucket < 4) {
                ordered_array[i] = possible_vals[randn];
                bucket++;
                i++;
            } else if (possible_vals[randn] == "clover" && clover < 2) {
                ordered_array[i] = possible_vals[randn];
                clover++;
                i++;
            } else if (possible_vals[randn] == "skull" && skull < 2) {
                ordered_array[i] = possible_vals[randn];
                skull++;
                i++;
            }
        }
    }

    void matrix_maker() // Adds ordered_array values to the card matrix
    {
        int row = 0;
        int col = 0;
        int i = 0;

        while (col < 3) {
            while (row < 4) {
                matrix[col][row].set_type(ordered_array[i]);
                row++;
                i++;
            }
            row = 0;
            col++;
        }
    }

    void matrix_reader() // Reads the card matrix
    {
        int row = 0;
        int col = 0;

        while (col < 3) {
            while (row < 4) {
                cout << matrix[col][row].get_type();
                row++;
            }
            row = 0;
            col++;
            cout << endl;
        }
    }

    void make_a_move() // Asks for player to choose a pair and verifies it
    {
        int col;
        int row;
        int col2;
        int row2;
        cout << "Choose a column" << endl;
        cin >> col;
        cout << "Choose a row" << endl;
        cin >> row;
        cout << "Choose another column" << endl;
        cin >> col2;
        cout << "Choose another row" << endl;
        cin >> row2;

        if (col == col2 && row == row2) {
        } else {
            if (matrix[col][row].get_type() == matrix[col2][row2].get_type()) {
                matrix[col][row].set_taken();
                cout << "wow, you're very lucky";
            } else {
                cout << "tough luck";
            }
        }
    }
};

/*
int main()
{
    srand(time(nullptr));
    Game_logic g1;
    g1.shuffler();
    g1.matrix_maker();
    g1.matrix_reader();

    return 0;
}
*/
