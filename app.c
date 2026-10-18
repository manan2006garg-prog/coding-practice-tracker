#include <stdio.h>
#include <string.h>

#define DB "problems.txt"
#define LINE 512
static int clean(const char *s) { return !strchr(s, '|') && !strchr(s, '\n') && !strchr(s, '\r'); }
static void usage(void) { puts("Coding Practice Tracker\n  practice-tracker add TITLE PLATFORM DIFFICULTY TOPIC\n  practice-tracker list\n  practice-tracker summary\nDifficulty: easy, medium, hard"); }
int main(int argc, char **argv) {
    FILE *f; char line[LINE], title[160], platform[80], level[32], topic[80]; int easy=0, medium=0, hard=0;
    if (argc == 2 && (!strcmp(argv[1], "list") || !strcmp(argv[1], "summary"))) {
        f = fopen(DB, "r"); if (!f) { puts("No problems logged yet."); return 0; }
        while (fgets(line, sizeof line, f)) if (sscanf(line, "%159[^|]|%79[^|]|%31[^|]|%79[^\n]", title, platform, level, topic) == 4) {
            if (!strcmp(argv[1], "list")) printf("%s | %s | %s | %s\n", title, platform, level, topic);
            if (!strcmp(level,"easy")) easy++; else if (!strcmp(level,"medium")) medium++; else if (!strcmp(level,"hard")) hard++;
        }
        fclose(f); if (!strcmp(argv[1], "summary")) printf("Easy: %d\nMedium: %d\nHard: %d\nTotal: %d\n", easy, medium, hard, easy+medium+hard); return 0;
    }
    if (argc != 6 || strcmp(argv[1], "add")) { usage(); return 1; }
    if ((strcmp(argv[4],"easy") && strcmp(argv[4],"medium") && strcmp(argv[4],"hard")) || !clean(argv[2]) || !clean(argv[3]) || !clean(argv[4]) || !clean(argv[5])) {
        fputs("Invalid difficulty or field. Fields cannot contain |.\n", stderr); return 1;
    }
    f = fopen(DB, "a"); if (!f) { perror(DB); return 1; }
    fprintf(f, "%s|%s|%s|%s\n", argv[2], argv[3], argv[4], argv[5]); fclose(f);
    puts("Problem logged."); return 0;
}
