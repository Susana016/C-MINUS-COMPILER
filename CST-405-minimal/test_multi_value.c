/* TEST: Multi-Value Equality Check Feature
 * This tests the new "is" operator for checking if a value
 * matches any value in a list
 */

int main() {
    int day;
    int month;
    int score;

    day = 0;
    month = 2;
    score = 85;

    /* Test 1: Check if day is a weekend (0 or 6) */
    if (day is 0, 6) {
        print(1);  /* Should print: it's a weekend! */
    }

    /* Test 2: Check if month has 31 days */
    if (month is 1, 3, 5, 7, 8, 10, 12) {
        print(31);  /* Should print 31 */
    } else {
        print(30);  /* Should print 30 or less */
    }

    /* Test 3: Check if score is in a specific range of values */
    if (score is 85, 90, 95, 100) {
        print(999);  /* Should print: excellent score! */
    }

    /* Test 4: Simple two-value check */
    if (day is 5, 6) {
        print(777);
    } else {
        print(888);  /* Should print: not Friday or Saturday */
    }

    return 0;
}
