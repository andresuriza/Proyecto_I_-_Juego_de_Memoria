#include <iostream>
#include <QByteArray>
#include <QPixmap>
#include <QBuffer>
#include "mainwindow.h"
#include <QApplication>
#include <utility>

using namespace std;

/**
 * Creates a card with information about its type, image and if it has been taken or not
 *
 */
class Card {
private:
    QByteArray image;
    string type;
    bool taken = false;

public:
    void set_type(string val) // Sets the type of the card
    {
        type = std::move(val);
    }

    void change_status() // Changes the taken status boolean value
    {
        if (!taken) { this->taken = true; }

        else if (taken) { this->taken = false; }
    }

    void set_image(QByteArray img) // Sets the image bytearray of the card
    {
        image = std::move(img);
    }

    string get_type() { return type; } // Returns card type

    QByteArray get_image() { return image; } // Returns image byte array

    bool get_taken() { return taken; } // Returns boolean status of taken
};

/**
 * Contains info about the order of the cards in the game and handles their creation
 *
 */
class Game_logic {
private:
    Card matrix[3][4]; // Only 4 in memory
    string possible_vals[12];
    string ordered_array[12];
    QByteArray clover_byte;
    QByteArray sun_byte;
    QByteArray bucket_byte;
    QByteArray skull_byte;

public:
    Game_logic() // Constructor method
    {
        ImageSaver();
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

    void ImageSaver() // Loads PNG images and saves them as byte arrays
    {
        QPixmap clover_img("../images/clover.png");
        QPixmap sun_img("../images/sun.png");
        QPixmap bucket_img("../images/bucket.png");
        QPixmap skull_img("../images/skull.png");

        QBuffer clover_buffer(&clover_byte);
        QBuffer sun_buffer(&sun_byte);
        QBuffer bucket_buffer(&bucket_byte);
        QBuffer skull_buffer(&skull_byte);

        clover_buffer.open(QIODevice::WriteOnly);
        clover_img.save(&clover_buffer, "PNG");

        sun_buffer.open(QIODevice::WriteOnly);
        sun_img.save(&sun_buffer, "PNG");

        bucket_buffer.open(QIODevice::WriteOnly);
        bucket_img.save(&bucket_buffer, "PNG");

        skull_buffer.open(QIODevice::WriteOnly);
        skull_img.save(&skull_buffer, "PNG");
    }



    void shuffler()
    { // Creates an array of pairs and arranges them in a random order
        string types_array[4] = {"sun", "bucket", "clover", "skull"};
        string a;
        int i = 0;
        int k = 0;
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
                if (ordered_array[i] == "clover") {
                    matrix[col][row].set_image(clover_byte);
                } else if (ordered_array[i] == "sun") {
                    matrix[col][row].set_image(sun_byte);
                } else if (ordered_array[i] == "bucket") {
                    matrix[col][row].set_image(bucket_byte);
                } else if (ordered_array[i] == "skull") {
                    matrix[col][row].set_image(skull_byte);
                }

                matrix[col][row].set_type(ordered_array[i]);
                row++;
                i++;
            }
            row = 0;
            col++;
        }
    }
    
    Card matrix_selector(int col, int row) { return matrix[col][row]; } // Returns a selected card from matrix

    void matrix_changer(int col, int row) { matrix[col][row].change_status(); } // Changes the boolean status of
                                                                                // selected card

    void CardArrayMaker() // Makes a card array
    {
        srand(time(nullptr));
        shuffler();
        matrix_maker();
    }
};