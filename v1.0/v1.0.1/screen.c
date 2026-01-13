// screen.c
#define VIDEO_MEMORY 0xB8000
#define WHITE_ON_BLACK 0x0F

void clear_screen() {
    char* video_memory = (char*)VIDEO_MEMORY;
    for (int i = 0; i < 80 * 25 * 2; i += 2) {
        video_memory[i] = ' ';
        video_memory[i + 1] = WHITE_ON_BLACK;
    }
}

void print_char(char c, int x, int y) {
    char* video_memory = (char*)VIDEO_MEMORY;
    int offset = (y * 80 + x) * 2;
    video_memory[offset] = c;
    video_memory[offset + 1] = WHITE_ON_BLACK;
}

void print_string(const char* str, int x, int y) {
    int i = 0;
    while (str[i] != '\0') {
        print_char(str[i], x + i, y);
        i++;
    }
}