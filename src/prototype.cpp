int create_images(){
    
    Canvas image(width, height, block_size);

    for(const auto &vector : glife_coord){
        image.clear(color_pallet[string_name]);
        for(const auto &point : vector){
            size_t pixel_x = point.row * block_size;
            size_t pixel_y = point.column * block_size;
            image.pixel(pixel_x, pixel_y, color_pallet[string_name]);   
        }
        encode_png(filename, image.pixels(), image.width(), image.height());
    }
    return 0;    
}