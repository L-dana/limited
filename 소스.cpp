1 #include <fcntl.h>                                                                                                    2 #include <unistd.h>                                                                                                   3 #include <stdlib.h>                                                                                                   4 #include <stdio.h>                                                                                                    5                                                                                                                       6 int main(int argc, char* argv[]) { 7     int fd, n;                                                                                                         8     char red[1] = { '1' };                                                                                                9                                                                                                                      10     if (argc != 2) { 11         printf("command-line-error");                                                                                12         return 0;                                                                                                    13 }                                                                                                                14                                                                                                                      15     fd = open(argv[1], O_RDONLY);                                                                                      16     if (fd == -1) { 17         perror("open error");                                                                                        18         exit(1);                                                                                                     19 }                                                                                                                20                                                                                                                      21     for (int i = 1; red != '\0'; i++) { 22         printf("%3d ", i);                                                                                            23         while (red != '\n') { 24             red = read(fd, red, 1);                                                                                      25             printf("%s", red);                                                                                        26 }                                                                                                            27         printf("\n");                                                                                                28 }                                                                                                                29     close(fd);                                                                                                       30     return 0;                                                                                                        31 }                                                                                                                    32                                                                                                                         1 #include <fcntl.h>                                                                                                    2 #include <unistd.h>                                                                                                   3 #include <stdlib.h>                                                                                                   4 #include <stdio.h>                                                                                                    5                                                                                                                       6 int main(int argc, char* argv[]) { 7     int fd, n;                                                                                                         8     char red[1] = { '1' };                                                                                                9                                                                                                                      10     if (argc != 2) { 11         printf("command-line-error");                                                                                12         return 0;                                                                                                    13 }                                                                                                                14                                                                                                                      15     fd = open(argv[1], O_RDONLY);                                                                                      16     if (fd == -1) { 17         perror("open error");                                                                                        18         exit(1);                                                                                                     19 }                                                                                                                20                                                                                                                      21     for (int i = 1; red != '\0'; i++) { 22         printf("%3d ", i);                                                                                            23         while (red != '\n') { 24             red = read(fd, red, 1);                                                                                      25             printf("%s", red);                                                                                        26 }                                                                                                            27         printf("\n");                                                                                                28 }                                                                                                                29     close(fd);                                                                                                       30     return 0;                                                                                                        31 }                                                                                                                    32                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           1 #include <fcntl.h>                                                                                                    2 #include <unistd.h>                                                                                                   3 #include <stdlib.h>                                                                                                   4 #include <stdio.h>                                                                                                    5                                                                                                                       6 int main(int argc, char* argv[]) { 7     int fd, n;                                                                                                         8     char red[1] = { '1' };                                                                                                9                                                                                                                      10     if (argc != 2) { 11         printf("command-line-error");                                                                                12         return 0;                                                                                                    13 }                                                                                                                14                                                                                                                      15     fd = open(argv[1], O_RDONLY);                                                                                      16     if (fd == -1) { 17         perror("open error");                                                                                        18         exit(1);                                                                                                     19 }                                                                                                                20                                                                                                                      21     for (int i = 1; red != '\0'; i++) { 22         printf("%3d ", i);                                                                                            23         while (red != '\n') { 24             red = read(fd, red, 1);                                                                                      25             printf("%s", red);                                                                                        26 }                                                                                                            27         printf("\n");                                                                                                28 }                                                                                                                29     close(fd);                                                                                                       30     return 0;                                                  #include <fcntl.h>                                                                                                    2 #include <unistd.h>                                                                                                   3 #include <stdlib.h>                                                                                                   4 #include <stdio.h>                                                                                                    5                                                                                                                       6 int main(int argc, char* argv[]) { 7     int fd, n;                                                                                                         8     char red[1] = { '1' };                                                                                                9                                                                                                                      10     if (argc != 2) { 11         printf("command-line-error");                                                                                12         return 0;                                                                                                    13 }                                                                                     31 }                                                                                                                    32