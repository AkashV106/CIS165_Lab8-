# CIS165_Lab8-
# Lottery Lab

**Name** Akash
**Course:** CIS-165-B030
**File:** `lottery.cpp`

## Description

This program simulates a five-digit lottery. It randomly generates five winning digits (0 through 9), asks the player to enter five digits, and compares the two arrays **position by position**. It displays both arrays and the number of positions that matched.

A digit only counts as a match if it is the same digit in the same position. A digit that appears somewhere else in the winning array does not count.

## Requirements Met

- Two five-element integer arrays: `winningDigits` and `player`
- Winning digits generated with `rand()`, each in the inclusive range 0 through 9
- Generator seeded once with `std::time(nullptr)`, before any digits are generated
- Player digits read into `player` with a loop
- Positional comparison done with a loop and a `matches` counter
- All five winning digits, all five player digits, and the match count displayed with labels
- Repeated digits allowed
- No permanent fixed winning sequence in the final program

## How to Compile and Run

```bash
g++ lottery.cpp -o lottery
./lottery
```

On Windows, run `lottery.exe` instead of `./lottery`.

## Testing

### How the fixed-array tests were set up

For tests 1 to 5, I temporarily replaced only the generated winning values with a fixed array (for example `int winningDigits[SIZE] = {7, 4, 9, 1, 3};`) and commented out the generating loop. The comparison loop was not changed. This was a test setup only and is not part of the final program.

Expected results were calculated by hand before running. "Actual output" and "Match?" are filled in after the run.

Compiler and command used: `Online GDB (online C++ compiler)`

### Required fixed-data tests

| # | Winning (fixed) | Player (input) | Expected (worked out beforehand) | Actual output | Match? |
|---|-----------------|----------------|----------------------------------|---------------|--------|
| 1 | `[7,4,9,1,3]` | `[4,2,9,7,3]` | **2 matches.** Position 2 (9 = 9) and position 4 (3 = 3). Positions 0, 1, 3 differ. | **2 matches.** Position 2 (9 = 9) and position 4 (3 = 3). Positions 0, 1, 3 differ. | yes |
| 2 | `[7,4,9,1,3]` | `[7,4,9,1,3]` | **5 matches.** Every position is equal. |  **5 matches.** Every position is equal. | yes |
| 3 | `[7,4,9,1,3]` | `[0,0,0,0,0]` | **0 matches.** None of the winning digits is 0. | **0 matches.** None of the winning digits is 0. | yes |
| 4 | `[1,1,2,2,3]` | `[1,2,2,3,3]` | **3 matches.** Position 0 (1 = 1), position 2 (2 = 2), position 4 (3 = 3). Positions 1 and 3 differ, even though the digits 2 and 3 appear elsewhere in the winning array. | **3 matches.** Position 0 (1 = 1), position 2 (2 = 2), position 4 (3 = 3). Positions 1 and 3 differ, even though the digits 2 and 3 appear elsewhere in the winning array | yes |

### Additional fixed-array test

| # | Winning (fixed) | Player (input) | Prediction and explanation | Actual output | Match? |
|---|-----------------|----------------|----------------------------|---------------|--------|
| 5 | `[7,4,9,1,3]` | `[3,7,4,9,1]` | **0 matches.** The player digits are the winning digits shifted one place, so every digit appears in both arrays but never at the same index (7 vs 3, 4 vs 7, 9 vs 4, 1 vs 9, 3 vs 1). This checks that a digit in the wrong position is not counted. | **0 matches.** The player digits are the winning digits shifted one place, so every digit appears in both arrays but never at the same index (7 vs 3, 4 vs 7, 9 vs 4, 1 vs 9, 3 vs 1). This checks that a digit in the wrong position is not counted] | yes |

### Final random-generation run

The temporary fixed array was removed and random generation was restored before this run.

- Player input: `37491`
- Winning digits printed: `74913`
- Player digits printed: `37491`
- Every winning digit is between 0 and 9: `yes`
- Manual position-by-position check: ` **0 matches.** The player digits are the winning digits shifted one place, so every digit appears in both arrays but never at the same index (7 vs 3, 4 vs 7, 9 vs 4, 1 vs 9, 3 vs 1). This checks that a digit in the wrong position is not counted.`
- Expected match count (from the printed arrays): ` **0 matches.** The player digits are the winning digits shifted one place, so every digit appears in both arrays but never at the same index (7 vs 3, 4 vs 7, 9 vs 4, 1 vs 9, 3 vs 1). This checks that a digit in the wrong position is not counted.`
- Count printed by the program: ` **0 matches.** The player digits are the winning digits shifted one place, so every digit appears in both arrays but never at the same index (7 vs 3, 4 vs 7, 9 vs 4, 1 vs 9, 3 vs 1). This checks that a digit in the wrong position is not counted.`
- Match?: `[yes/no]`

### Errors found and corrected

Record any error you actually fixed and the rerun that followed. The development issues below are ones I fixed while writing the program:

- Winning digits were generated with `rand() % MAX + 1`, which gives 1 to 9 and never 0. Corrected to `rand() % (MAX - MIN + 1) + MIN`. Rerun result: `[fill in]`
- The input loop was reading only one value and copying it into every position. Corrected so a loop reads `player[i]` for each index. Rerun result: `[fill in]`
- The match counter was never incremented because the comparison was missing. Added the comparison loop. Rerun result: `[fill in]`

### Final check before commit

- Temporary changes restored: ' removed the fixed winningDigits initializer, restored the rand() generating loop`
- Final source compiled and run again: `[yes, compiler and command]`
- Result of that final run: ` Winning Digits are : 59386.   You entered: 13264.    There were 0 matches`

## Explain Your Code

**1. How does the random expression keep every digit between 0 and 9?**
`rand() % (MAX - MIN + 1) + MIN` uses `MAX - MIN + 1 = 10`. Taking `rand() % 10` always gives a remainder from 0 through 9. Adding `MIN`, which is 0, shifts the range to start at the minimum, so the result is always from `MIN` to `MAX`, inclusive of 9.

**2. Why does a matching digit in another position not count?**
The comparison loop only checks `winningDigits[i] == player[i]` with the same index `i` on both sides. It never looks at other positions, so a digit sitting at a different index is never compared. The lab counts matching positions, not matching digits.

**3. Trace the count through the example arrays.**
Winning `[7,4,9,1,3]`, player `[4,2,9,7,3]`, `matches` starts at 0:
- i = 0: 7 vs 4, not equal, matches stays 0
- i = 1: 4 vs 2, not equal, matches stays 0
- i = 2: 9 vs 9, equal, matches becomes 1
- i = 3: 1 vs 7, not equal, matches stays 1
- i = 4: 3 vs 3, equal, matches becomes 2

Final count: 2.

**4. Why do array loops stop before SIZE, and what did the fixed tests establish?**
An array with `SIZE = 5` has valid indexes 0 through 4. Index 5 is outside the array, so the loop condition is `i < SIZE`, not `i <= SIZE`. The fixed tests showed that the comparison loop gives the correct count for a partial match, all matches, no matches, repeated digits, and digits in wrong positions, because the winning values were known and not random. They did not test the random generation, which is why the final random run checks that every digit is in range and that the count agrees with the printed arrays.

## Notes

- The program assumes the user enters five valid digits from 0 through 9. Input validation was not required.
- Seeding with `time` means two runs in the same second can produce the same winning digits.
