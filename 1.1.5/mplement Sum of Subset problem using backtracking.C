#include <stdio.h>

int a[20], subset[20];
int result[1000][20];
int size[1000];
int count = 0;

void findSubsets(int index, int n, int target, int sum, int k) {
    if (sum == target) {
        size[count] = k;
        for (int i = 0; i < k; i++)
            result[count][i] = subset[i];
        count++;
        return;
    }

    if (index == n || sum > target)
        return;

    subset[k] = a[index];
    findSubsets(index + 1, n, target, sum + a[index], k + 1);

    findSubsets(index + 1, n, target, sum, k);
}

int main() {
    int n, target;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &target);

    findSubsets(0, n, target, 0, 0);

    if (count == 0) {
        printf("-1");
    } else {
        for (int i = count - 1; i >= 0; i--) {
            for (int j = 0; j < size[i]; j++)
                printf("%d ", result[i][j]);
            printf("\n");
        }
    }

    return 0;
}
