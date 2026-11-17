**AI_REFLECTION**
**Tools**: I used Claude to turn my plan into pseudocode, review my code, and help organize the README. I wrote the code and ran every test myself in Online GDB.

**One decision**: My first version generated digits with rand() % MAX + 1, which Claude pointed out gives 1 to 9 and never 0. I accepted that correction and changed it to rand() % (MAX - MIN + 1) + MIN. Claude also suggested reading digits one character at a time so I wouldn’t have to press Enter. I rejected that and kept cin >> player[i], because it is simpler and the lab allows it.

**A specific check**: On a random run, I entered 1 0 5 7 4 and the winning digits were 1 9 4 5 6. I first wrote “no match,” but checking position by position showed the first digit is 1 in both arrays, so the correct count was 1 and my “no match” was a typo. The program’s count agreed with my hand count. This showed that the comparison loop counts same-position matches, and that I should check my own records against the printed arrays.

**Learning** I can now compare two arrays position by position with a loop and a counter, and test it with fixed arrays whose expected result I work out first. I still need to practice explaining the rand() range expression without looking at it, and writing my own test cases before running the program.
