#include <fstream>
#include <iostream>
#include <vector>

#include "canvas.h"
#include "../ext_lib/lodepng.h"

using namespace life;
// The image argument has width * height RGBA pixels or width * height * 4 bytes

void encode_png(const char* filename, const unsigned char* image, unsigned width, unsigned height) {
    // Encode the image
    unsigned error = lodepng::encode(filename, image, width, height);

    // if there's an error, display it
    if(error != 0U){ std::cout << "encoder error " << error << ": " << lodepng_error_text(error) << std::endl; }
}

int main(int argc, char* argv[]) {
    const char* filename = argc > 1 ? argv[1] : "test.png";

    // Test parameters: generate some image
    unsigned width = 20;
    unsigned height = 15;
    short block_size = 100;

    // Criar uma imagem para desenho.
    Canvas image(width, height, block_size);

    // Preenche os pixels da imagem com um tabuleiro.

// Preenche os pixels da imagem com um tabuleiro.
for (auto x{ 0U }; x < width * block_size; x++) {
    for (auto y{ 0U }; y < height * block_size; y++) {
        // Calcula o índice do bloco atual
        size_t block_x = x / block_size;
        size_t block_y = y / block_size;

        // Define a cor baseado no bloco
        if ((block_y % 2) != 0U) {
            if ((block_x % 2) == 0U) {
                image.pixel(x, y, color_pallet["deep_sky_blue"]);
            } else {
                image.pixel(x, y, color_pallet["red"]);
            }
        } else {
            if ((block_x % 2) == 0U) {
                image.pixel(x, y, RED);
            } else {
                image.pixel(x, y, DEEP_SKY_BLUE);
            }
        }
    }
}
    image.clear(color_pallet["yellow"]);
    // Definindo um pixel específico como verde (GREEN)
    image.pixel(5, 2, color_pallet["green"]);

    std::cout << ">>> Gravando imagem '" << filename << "', dimensions: " << width << " x " << height
              << " (bs = " << block_size << "), please wait...\n";

    // Salvar como PNG
    encode_png(filename, image.pixels(), image.width(), image.height());

    std::cout << "<<< done!\n";

    return 0;
}
