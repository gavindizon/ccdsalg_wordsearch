int isCharacter (char c) {
	int ctr;
	char notAllowed[20] = {' ', '.', ',', '?', ';', '!', ':', '\'', '(', ')', '[', ']', '\"', '-', '/', '@', '{', '}', '\0', '\n'};
	
	for (ctr = 0; ctr < 20; ctr++) {
		if (c == notAllowed[ctr])
			return 0;
	}
	
	return 1;
}

int tokenizer (String fileName, String words[]) {
	int ctr = 0, wordCount = 0;
	char c;
	String word;
	FILE *fp;
	
	fp = fopen(fileName, "r");
		while (fscanf(fp, "%c", &c) == 1) {
			if (c >= 65 && c <= 90)
				c = tolower(c);
			
			if (isCharacter(c)) {
				word[ctr] = c;
				ctr++;
			} 
			
			else if (isCharacter(c) == 0) {
				word[ctr] = '\0';
				ctr = 0;
				
				if (strlen(word) >= 3) {
					strcpy(words[wordCount], word);
					wordCount++;
					
					memset(word, 0, sizeof(word));
				}
			}
		}
		
		if (strlen(word) >= 3) {
			strcpy(words[wordCount], word);
			wordCount++;
			
			memset(word, 0, sizeof(word));
		}

	
	fclose(fp);
	return wordCount;

}
