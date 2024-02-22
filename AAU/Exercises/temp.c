int hashKey(char *str){
	return str[0] * 10000 + str[1] * 100 + str[2];
}