#include <stdio.h>

void findCombinations(int score, int td, int td2pt, int tdFg, int fg, int safety) {
    if (score == 0) {
        printf("%d TD + %d TD + FG + %d TD + 2pt, %d 3pt FG, %d Safety\n", td, td2pt, tdFg, fg, safety);
        return;
    }
    if (score < 0) {
        return;
    }
    
    // Try each scoring play and reduce the score
    findCombinations(score - 6, td + 1, td2pt, tdFg, fg, safety); // TD
    findCombinations(score - 8, td, td2pt + 1, tdFg, fg, safety); // TD + 2pt
    findCombinations(score - 7, td, td2pt, tdFg + 1, fg, safety); // TD + FG
    findCombinations(score - 3, td, td2pt, tdFg, fg + 1, safety); // Field Goal
    findCombinations(score - 2, td, td2pt, tdFg, fg, safety + 1); // Safety
}

int main() {
    int score;

    while (1) {
        printf("Enter the NFL score (0 or less to STOP): ");
        scanf("%d", &score);

        if (score <= 0) {
            break;
        }

        printf("Possible combinations of scoring plays if a team's score is %d:\n", score);
        findCombinations(score, 0, 0, 0, 0, 0);
    }

    return 0;
}