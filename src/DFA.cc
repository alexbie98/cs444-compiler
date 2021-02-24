#include "../src/DFA.h"

#include <utility>
#include <iostream>
const std::pair<TokenType, long> longestPrefixRecognize(size_t start, const std::string &s)
{
std::pair<TokenType, long> last_accepted(REJECT, -1);

S_0:
switch(s[start])
{
	case '\t': goto S_110;
	case '\n': goto S_112;
	case '\f': goto S_104;
	case ' ': goto S_107;
	case '!': goto S_1022;
	case '\"': goto S_795;
	case '$': goto S_877;
	case '%': goto S_1023;
	case '&': goto S_1024;
	case '\'': goto S_748;
	case '(': goto S_141;
	case ')': goto S_143;
	case '*': goto S_1025;
	case '+': goto S_1026;
	case ',': goto S_155;
	case '-': goto S_1027;
	case '.': goto S_157;
	case '/': goto S_1028;
	case '0': goto S_1029;
	case '1': goto S_851;
	case '2': goto S_851;
	case '3': goto S_851;
	case '4': goto S_851;
	case '5': goto S_851;
	case '6': goto S_851;
	case '7': goto S_851;
	case '8': goto S_851;
	case '9': goto S_851;
	case ':': goto S_907;
	case ';': goto S_153;
	case '<': goto S_1030;
	case '=': goto S_1031;
	case '>': goto S_1032;
	case '?': goto S_905;
	case 'A': goto S_874;
	case 'B': goto S_874;
	case 'C': goto S_874;
	case 'D': goto S_874;
	case 'E': goto S_874;
	case 'F': goto S_874;
	case 'G': goto S_874;
	case 'H': goto S_874;
	case 'I': goto S_874;
	case 'J': goto S_874;
	case 'K': goto S_874;
	case 'L': goto S_874;
	case 'M': goto S_874;
	case 'N': goto S_874;
	case 'O': goto S_874;
	case 'P': goto S_874;
	case 'Q': goto S_874;
	case 'R': goto S_874;
	case 'S': goto S_874;
	case 'T': goto S_874;
	case 'U': goto S_874;
	case 'V': goto S_874;
	case 'W': goto S_874;
	case 'X': goto S_874;
	case 'Y': goto S_874;
	case 'Z': goto S_874;
	case '[': goto S_1033;
	case ']': goto S_151;
	case '^': goto S_1034;
	case '_': goto S_879;
	case 'a': goto S_1035;
	case 'b': goto S_1036;
	case 'c': goto S_1037;
	case 'd': goto S_1038;
	case 'e': goto S_1039;
	case 'f': goto S_1040;
	case 'g': goto S_1041;
	case 'h': goto S_871;
	case 'i': goto S_1042;
	case 'j': goto S_871;
	case 'k': goto S_871;
	case 'l': goto S_1043;
	case 'm': goto S_871;
	case 'n': goto S_1044;
	case 'o': goto S_871;
	case 'p': goto S_1045;
	case 'q': goto S_871;
	case 'r': goto S_1046;
	case 's': goto S_1047;
	case 't': goto S_1048;
	case 'u': goto S_871;
	case 'v': goto S_1049;
	case 'w': goto S_1050;
	case 'x': goto S_871;
	case 'y': goto S_871;
	case 'z': goto S_871;
	case '{': goto S_145;
	case '|': goto S_1051;
	case '}': goto S_147;
	case '~': goto S_903;
	default: last_accepted.second++; return last_accepted;
}

S_104:
last_accepted = {WS,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_107:
last_accepted = {WS,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_110:
last_accepted = {WS,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_112:
last_accepted = {WS,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_115:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '/': goto S_117;
	default: last_accepted.second++; return last_accepted;
}

S_117:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '\n': goto S_121;
	default: goto S_119;
}

S_119:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '\n': goto S_121;
	default: goto S_119;
}

S_121:
last_accepted = {COMMENT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_123:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '*': goto S_125;
	default: last_accepted.second++; return last_accepted;
}

S_125:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '*': goto S_1099;
	default: goto S_1100;
}

S_129:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '*': goto S_129;
	case '/': goto S_1101;
	default: goto S_131;
}

S_131:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '*': goto S_1099;
	default: goto S_1100;
}

S_133:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '*': goto S_1102;
	default: goto S_133;
}

S_137:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '/': goto S_139;
	default: last_accepted.second++; return last_accepted;
}

S_139:
last_accepted = {COMMENT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_141:
last_accepted = {LPAREN,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_143:
last_accepted = {RPAREN,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_145:
last_accepted = {LBRACE,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_147:
last_accepted = {RBRACE,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_149:
last_accepted = {LBRACKET,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_151:
last_accepted = {RBRACKET,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_153:
last_accepted = {SEMICOLON,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_155:
last_accepted = {COMMA,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_157:
last_accepted = {DOT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_159:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'f': goto S_161;
	default: last_accepted.second++; return last_accepted;
}

S_161:
last_accepted = {IF,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_163:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'l': goto S_165;
	default: last_accepted.second++; return last_accepted;
}

S_165:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 's': goto S_167;
	default: last_accepted.second++; return last_accepted;
}

S_167:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'e': goto S_169;
	default: last_accepted.second++; return last_accepted;
}

S_169:
last_accepted = {ELSE,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_171:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'h': goto S_173;
	default: last_accepted.second++; return last_accepted;
}

S_173:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'i': goto S_175;
	default: last_accepted.second++; return last_accepted;
}

S_175:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'l': goto S_177;
	default: last_accepted.second++; return last_accepted;
}

S_177:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'e': goto S_179;
	default: last_accepted.second++; return last_accepted;
}

S_179:
last_accepted = {WHILE,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_181:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'o': goto S_183;
	default: last_accepted.second++; return last_accepted;
}

S_183:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'r': goto S_185;
	default: last_accepted.second++; return last_accepted;
}

S_185:
last_accepted = {FOR,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_187:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'l': goto S_189;
	default: last_accepted.second++; return last_accepted;
}

S_189:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'a': goto S_191;
	default: last_accepted.second++; return last_accepted;
}

S_191:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 's': goto S_193;
	default: last_accepted.second++; return last_accepted;
}

S_193:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 's': goto S_195;
	default: last_accepted.second++; return last_accepted;
}

S_195:
last_accepted = {CLASS,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_197:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'x': goto S_199;
	default: last_accepted.second++; return last_accepted;
}

S_199:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 't': goto S_201;
	default: last_accepted.second++; return last_accepted;
}

S_201:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'e': goto S_203;
	default: last_accepted.second++; return last_accepted;
}

S_203:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'n': goto S_205;
	default: last_accepted.second++; return last_accepted;
}

S_205:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'd': goto S_207;
	default: last_accepted.second++; return last_accepted;
}

S_207:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 's': goto S_209;
	default: last_accepted.second++; return last_accepted;
}

S_209:
last_accepted = {EXTENDS,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_211:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'm': goto S_213;
	default: last_accepted.second++; return last_accepted;
}

S_213:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'p': goto S_215;
	default: last_accepted.second++; return last_accepted;
}

S_215:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'l': goto S_217;
	default: last_accepted.second++; return last_accepted;
}

S_217:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'e': goto S_219;
	default: last_accepted.second++; return last_accepted;
}

S_219:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'm': goto S_221;
	default: last_accepted.second++; return last_accepted;
}

S_221:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'e': goto S_223;
	default: last_accepted.second++; return last_accepted;
}

S_223:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'n': goto S_225;
	default: last_accepted.second++; return last_accepted;
}

S_225:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 't': goto S_227;
	default: last_accepted.second++; return last_accepted;
}

S_227:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 's': goto S_229;
	default: last_accepted.second++; return last_accepted;
}

S_229:
last_accepted = {IMPLEMENTS,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_231:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'n': goto S_233;
	default: last_accepted.second++; return last_accepted;
}

S_233:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 't': goto S_235;
	default: last_accepted.second++; return last_accepted;
}

S_235:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'e': goto S_237;
	default: last_accepted.second++; return last_accepted;
}

S_237:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'r': goto S_239;
	default: last_accepted.second++; return last_accepted;
}

S_239:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'f': goto S_241;
	default: last_accepted.second++; return last_accepted;
}

S_241:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'a': goto S_243;
	default: last_accepted.second++; return last_accepted;
}

S_243:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'c': goto S_245;
	default: last_accepted.second++; return last_accepted;
}

S_245:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'e': goto S_247;
	default: last_accepted.second++; return last_accepted;
}

S_247:
last_accepted = {INTERFACE,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_249:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'h': goto S_251;
	default: last_accepted.second++; return last_accepted;
}

S_251:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'i': goto S_253;
	default: last_accepted.second++; return last_accepted;
}

S_253:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 's': goto S_255;
	default: last_accepted.second++; return last_accepted;
}

S_255:
last_accepted = {THIS,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_257:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'n': goto S_259;
	default: last_accepted.second++; return last_accepted;
}

S_259:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 's': goto S_261;
	default: last_accepted.second++; return last_accepted;
}

S_261:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 't': goto S_263;
	default: last_accepted.second++; return last_accepted;
}

S_263:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'a': goto S_265;
	default: last_accepted.second++; return last_accepted;
}

S_265:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'n': goto S_267;
	default: last_accepted.second++; return last_accepted;
}

S_267:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'c': goto S_269;
	default: last_accepted.second++; return last_accepted;
}

S_269:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'e': goto S_271;
	default: last_accepted.second++; return last_accepted;
}

S_271:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'o': goto S_273;
	default: last_accepted.second++; return last_accepted;
}

S_273:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'f': goto S_275;
	default: last_accepted.second++; return last_accepted;
}

S_275:
last_accepted = {INSTANCEOF,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_277:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'e': goto S_279;
	default: last_accepted.second++; return last_accepted;
}

S_279:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'w': goto S_281;
	default: last_accepted.second++; return last_accepted;
}

S_281:
last_accepted = {NEW,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_283:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 't': goto S_285;
	default: last_accepted.second++; return last_accepted;
}

S_285:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'a': goto S_287;
	default: last_accepted.second++; return last_accepted;
}

S_287:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 't': goto S_289;
	default: last_accepted.second++; return last_accepted;
}

S_289:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'i': goto S_291;
	default: last_accepted.second++; return last_accepted;
}

S_291:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'c': goto S_293;
	default: last_accepted.second++; return last_accepted;
}

S_293:
last_accepted = {STATIC,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_295:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'u': goto S_297;
	default: last_accepted.second++; return last_accepted;
}

S_297:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'b': goto S_299;
	default: last_accepted.second++; return last_accepted;
}

S_299:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'l': goto S_301;
	default: last_accepted.second++; return last_accepted;
}

S_301:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'i': goto S_303;
	default: last_accepted.second++; return last_accepted;
}

S_303:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'c': goto S_305;
	default: last_accepted.second++; return last_accepted;
}

S_305:
last_accepted = {PUBLIC,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_307:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'r': goto S_309;
	default: last_accepted.second++; return last_accepted;
}

S_309:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'i': goto S_311;
	default: last_accepted.second++; return last_accepted;
}

S_311:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'v': goto S_313;
	default: last_accepted.second++; return last_accepted;
}

S_313:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'a': goto S_315;
	default: last_accepted.second++; return last_accepted;
}

S_315:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 't': goto S_317;
	default: last_accepted.second++; return last_accepted;
}

S_317:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'e': goto S_319;
	default: last_accepted.second++; return last_accepted;
}

S_319:
last_accepted = {PRIVATE,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_321:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'r': goto S_323;
	default: last_accepted.second++; return last_accepted;
}

S_323:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'o': goto S_325;
	default: last_accepted.second++; return last_accepted;
}

S_325:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 't': goto S_327;
	default: last_accepted.second++; return last_accepted;
}

S_327:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'e': goto S_329;
	default: last_accepted.second++; return last_accepted;
}

S_329:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'c': goto S_331;
	default: last_accepted.second++; return last_accepted;
}

S_331:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 't': goto S_333;
	default: last_accepted.second++; return last_accepted;
}

S_333:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'e': goto S_335;
	default: last_accepted.second++; return last_accepted;
}

S_335:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'd': goto S_337;
	default: last_accepted.second++; return last_accepted;
}

S_337:
last_accepted = {PROTECTED,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_339:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'b': goto S_341;
	default: last_accepted.second++; return last_accepted;
}

S_341:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 's': goto S_343;
	default: last_accepted.second++; return last_accepted;
}

S_343:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 't': goto S_345;
	default: last_accepted.second++; return last_accepted;
}

S_345:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'r': goto S_347;
	default: last_accepted.second++; return last_accepted;
}

S_347:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'a': goto S_349;
	default: last_accepted.second++; return last_accepted;
}

S_349:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'c': goto S_351;
	default: last_accepted.second++; return last_accepted;
}

S_351:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 't': goto S_353;
	default: last_accepted.second++; return last_accepted;
}

S_353:
last_accepted = {ABSTRACT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_355:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'i': goto S_357;
	default: last_accepted.second++; return last_accepted;
}

S_357:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'n': goto S_359;
	default: last_accepted.second++; return last_accepted;
}

S_359:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'a': goto S_361;
	default: last_accepted.second++; return last_accepted;
}

S_361:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'l': goto S_363;
	default: last_accepted.second++; return last_accepted;
}

S_363:
last_accepted = {FINAL,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_365:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'a': goto S_367;
	default: last_accepted.second++; return last_accepted;
}

S_367:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 't': goto S_369;
	default: last_accepted.second++; return last_accepted;
}

S_369:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'i': goto S_371;
	default: last_accepted.second++; return last_accepted;
}

S_371:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'v': goto S_373;
	default: last_accepted.second++; return last_accepted;
}

S_373:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'e': goto S_375;
	default: last_accepted.second++; return last_accepted;
}

S_375:
last_accepted = {NATIVE,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_377:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'a': goto S_379;
	default: last_accepted.second++; return last_accepted;
}

S_379:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'c': goto S_381;
	default: last_accepted.second++; return last_accepted;
}

S_381:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'k': goto S_383;
	default: last_accepted.second++; return last_accepted;
}

S_383:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'a': goto S_385;
	default: last_accepted.second++; return last_accepted;
}

S_385:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'g': goto S_387;
	default: last_accepted.second++; return last_accepted;
}

S_387:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'e': goto S_389;
	default: last_accepted.second++; return last_accepted;
}

S_389:
last_accepted = {PACKAGE,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_391:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'm': goto S_393;
	default: last_accepted.second++; return last_accepted;
}

S_393:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'p': goto S_395;
	default: last_accepted.second++; return last_accepted;
}

S_395:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'o': goto S_397;
	default: last_accepted.second++; return last_accepted;
}

S_397:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'r': goto S_399;
	default: last_accepted.second++; return last_accepted;
}

S_399:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 't': goto S_401;
	default: last_accepted.second++; return last_accepted;
}

S_401:
last_accepted = {IMPORT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_403:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'e': goto S_405;
	default: last_accepted.second++; return last_accepted;
}

S_405:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 't': goto S_407;
	default: last_accepted.second++; return last_accepted;
}

S_407:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'u': goto S_409;
	default: last_accepted.second++; return last_accepted;
}

S_409:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'r': goto S_411;
	default: last_accepted.second++; return last_accepted;
}

S_411:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'n': goto S_413;
	default: last_accepted.second++; return last_accepted;
}

S_413:
last_accepted = {RETURN,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_415:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'o': goto S_417;
	default: last_accepted.second++; return last_accepted;
}

S_417:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'i': goto S_419;
	default: last_accepted.second++; return last_accepted;
}

S_419:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'd': goto S_421;
	default: last_accepted.second++; return last_accepted;
}

S_421:
last_accepted = {VOID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_423:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'n': goto S_425;
	default: last_accepted.second++; return last_accepted;
}

S_425:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 't': goto S_427;
	default: last_accepted.second++; return last_accepted;
}

S_427:
last_accepted = {INT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_429:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'o': goto S_431;
	default: last_accepted.second++; return last_accepted;
}

S_431:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'o': goto S_433;
	default: last_accepted.second++; return last_accepted;
}

S_433:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'l': goto S_435;
	default: last_accepted.second++; return last_accepted;
}

S_435:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'e': goto S_437;
	default: last_accepted.second++; return last_accepted;
}

S_437:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'a': goto S_439;
	default: last_accepted.second++; return last_accepted;
}

S_439:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'n': goto S_441;
	default: last_accepted.second++; return last_accepted;
}

S_441:
last_accepted = {BOOLEAN,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_443:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'h': goto S_445;
	default: last_accepted.second++; return last_accepted;
}

S_445:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'a': goto S_447;
	default: last_accepted.second++; return last_accepted;
}

S_447:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'r': goto S_449;
	default: last_accepted.second++; return last_accepted;
}

S_449:
last_accepted = {CHAR,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_451:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'y': goto S_453;
	default: last_accepted.second++; return last_accepted;
}

S_453:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 't': goto S_455;
	default: last_accepted.second++; return last_accepted;
}

S_455:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'e': goto S_457;
	default: last_accepted.second++; return last_accepted;
}

S_457:
last_accepted = {BYTE,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_459:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'h': goto S_461;
	default: last_accepted.second++; return last_accepted;
}

S_461:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'o': goto S_463;
	default: last_accepted.second++; return last_accepted;
}

S_463:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'r': goto S_465;
	default: last_accepted.second++; return last_accepted;
}

S_465:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 't': goto S_467;
	default: last_accepted.second++; return last_accepted;
}

S_467:
last_accepted = {SHORT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_469:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case ']': goto S_471;
	default: last_accepted.second++; return last_accepted;
}

S_471:
last_accepted = {ARRAY,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_473:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'o': goto S_475;
	default: last_accepted.second++; return last_accepted;
}

S_475:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'n': goto S_477;
	default: last_accepted.second++; return last_accepted;
}

S_477:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 's': goto S_479;
	default: last_accepted.second++; return last_accepted;
}

S_479:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 't': goto S_481;
	default: last_accepted.second++; return last_accepted;
}

S_481:
last_accepted = {CONST,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_483:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 't': goto S_485;
	default: last_accepted.second++; return last_accepted;
}

S_485:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'r': goto S_487;
	default: last_accepted.second++; return last_accepted;
}

S_487:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'i': goto S_489;
	default: last_accepted.second++; return last_accepted;
}

S_489:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'c': goto S_491;
	default: last_accepted.second++; return last_accepted;
}

S_491:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 't': goto S_493;
	default: last_accepted.second++; return last_accepted;
}

S_493:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'f': goto S_495;
	default: last_accepted.second++; return last_accepted;
}

S_495:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'p': goto S_497;
	default: last_accepted.second++; return last_accepted;
}

S_497:
last_accepted = {STRICTFP,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_499:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'y': goto S_501;
	default: last_accepted.second++; return last_accepted;
}

S_501:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'n': goto S_503;
	default: last_accepted.second++; return last_accepted;
}

S_503:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'c': goto S_505;
	default: last_accepted.second++; return last_accepted;
}

S_505:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'h': goto S_507;
	default: last_accepted.second++; return last_accepted;
}

S_507:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'r': goto S_509;
	default: last_accepted.second++; return last_accepted;
}

S_509:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'o': goto S_511;
	default: last_accepted.second++; return last_accepted;
}

S_511:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'n': goto S_513;
	default: last_accepted.second++; return last_accepted;
}

S_513:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'i': goto S_515;
	default: last_accepted.second++; return last_accepted;
}

S_515:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'z': goto S_517;
	default: last_accepted.second++; return last_accepted;
}

S_517:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'e': goto S_519;
	default: last_accepted.second++; return last_accepted;
}

S_519:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'd': goto S_521;
	default: last_accepted.second++; return last_accepted;
}

S_521:
last_accepted = {SYNCHRONIZED,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_523:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'r': goto S_525;
	default: last_accepted.second++; return last_accepted;
}

S_525:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'a': goto S_527;
	default: last_accepted.second++; return last_accepted;
}

S_527:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'n': goto S_529;
	default: last_accepted.second++; return last_accepted;
}

S_529:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 's': goto S_531;
	default: last_accepted.second++; return last_accepted;
}

S_531:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'i': goto S_533;
	default: last_accepted.second++; return last_accepted;
}

S_533:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'e': goto S_535;
	default: last_accepted.second++; return last_accepted;
}

S_535:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'n': goto S_537;
	default: last_accepted.second++; return last_accepted;
}

S_537:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 't': goto S_539;
	default: last_accepted.second++; return last_accepted;
}

S_539:
last_accepted = {TRANSIENT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_541:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'o': goto S_543;
	default: last_accepted.second++; return last_accepted;
}

S_543:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'l': goto S_545;
	default: last_accepted.second++; return last_accepted;
}

S_545:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'a': goto S_547;
	default: last_accepted.second++; return last_accepted;
}

S_547:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 't': goto S_549;
	default: last_accepted.second++; return last_accepted;
}

S_549:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'i': goto S_551;
	default: last_accepted.second++; return last_accepted;
}

S_551:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'l': goto S_553;
	default: last_accepted.second++; return last_accepted;
}

S_553:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'e': goto S_555;
	default: last_accepted.second++; return last_accepted;
}

S_555:
last_accepted = {VOLATILE,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_557:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'o': goto S_559;
	default: last_accepted.second++; return last_accepted;
}

S_559:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'u': goto S_561;
	default: last_accepted.second++; return last_accepted;
}

S_561:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'b': goto S_563;
	default: last_accepted.second++; return last_accepted;
}

S_563:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'l': goto S_565;
	default: last_accepted.second++; return last_accepted;
}

S_565:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'e': goto S_567;
	default: last_accepted.second++; return last_accepted;
}

S_567:
last_accepted = {DOUBLE,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_569:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'l': goto S_571;
	default: last_accepted.second++; return last_accepted;
}

S_571:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'o': goto S_573;
	default: last_accepted.second++; return last_accepted;
}

S_573:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'a': goto S_575;
	default: last_accepted.second++; return last_accepted;
}

S_575:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 't': goto S_577;
	default: last_accepted.second++; return last_accepted;
}

S_577:
last_accepted = {FLOAT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_579:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'o': goto S_581;
	default: last_accepted.second++; return last_accepted;
}

S_581:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'n': goto S_583;
	default: last_accepted.second++; return last_accepted;
}

S_583:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'g': goto S_585;
	default: last_accepted.second++; return last_accepted;
}

S_585:
last_accepted = {LONG,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_587:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'a': goto S_589;
	default: last_accepted.second++; return last_accepted;
}

S_589:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 't': goto S_591;
	default: last_accepted.second++; return last_accepted;
}

S_591:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'c': goto S_593;
	default: last_accepted.second++; return last_accepted;
}

S_593:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'h': goto S_595;
	default: last_accepted.second++; return last_accepted;
}

S_595:
last_accepted = {CATCH,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_597:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'i': goto S_599;
	default: last_accepted.second++; return last_accepted;
}

S_599:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'n': goto S_601;
	default: last_accepted.second++; return last_accepted;
}

S_601:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'a': goto S_603;
	default: last_accepted.second++; return last_accepted;
}

S_603:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'l': goto S_605;
	default: last_accepted.second++; return last_accepted;
}

S_605:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'l': goto S_607;
	default: last_accepted.second++; return last_accepted;
}

S_607:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'y': goto S_609;
	default: last_accepted.second++; return last_accepted;
}

S_609:
last_accepted = {FINALLY,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_611:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'h': goto S_613;
	default: last_accepted.second++; return last_accepted;
}

S_613:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'r': goto S_615;
	default: last_accepted.second++; return last_accepted;
}

S_615:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'o': goto S_617;
	default: last_accepted.second++; return last_accepted;
}

S_617:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'w': goto S_619;
	default: last_accepted.second++; return last_accepted;
}

S_619:
last_accepted = {THROW,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_621:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'h': goto S_623;
	default: last_accepted.second++; return last_accepted;
}

S_623:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'r': goto S_625;
	default: last_accepted.second++; return last_accepted;
}

S_625:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'o': goto S_627;
	default: last_accepted.second++; return last_accepted;
}

S_627:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'w': goto S_629;
	default: last_accepted.second++; return last_accepted;
}

S_629:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 's': goto S_631;
	default: last_accepted.second++; return last_accepted;
}

S_631:
last_accepted = {THROWS,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_633:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'r': goto S_635;
	default: last_accepted.second++; return last_accepted;
}

S_635:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'y': goto S_637;
	default: last_accepted.second++; return last_accepted;
}

S_637:
last_accepted = {TRY,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_639:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'u': goto S_641;
	default: last_accepted.second++; return last_accepted;
}

S_641:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'p': goto S_643;
	default: last_accepted.second++; return last_accepted;
}

S_643:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'e': goto S_645;
	default: last_accepted.second++; return last_accepted;
}

S_645:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'r': goto S_647;
	default: last_accepted.second++; return last_accepted;
}

S_647:
last_accepted = {SUPER,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_649:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'r': goto S_651;
	default: last_accepted.second++; return last_accepted;
}

S_651:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'e': goto S_653;
	default: last_accepted.second++; return last_accepted;
}

S_653:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'a': goto S_655;
	default: last_accepted.second++; return last_accepted;
}

S_655:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'k': goto S_657;
	default: last_accepted.second++; return last_accepted;
}

S_657:
last_accepted = {BREAK,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_659:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'a': goto S_661;
	default: last_accepted.second++; return last_accepted;
}

S_661:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 's': goto S_663;
	default: last_accepted.second++; return last_accepted;
}

S_663:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'e': goto S_665;
	default: last_accepted.second++; return last_accepted;
}

S_665:
last_accepted = {CASE,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_667:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'o': goto S_669;
	default: last_accepted.second++; return last_accepted;
}

S_669:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'n': goto S_671;
	default: last_accepted.second++; return last_accepted;
}

S_671:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 't': goto S_673;
	default: last_accepted.second++; return last_accepted;
}

S_673:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'i': goto S_675;
	default: last_accepted.second++; return last_accepted;
}

S_675:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'n': goto S_677;
	default: last_accepted.second++; return last_accepted;
}

S_677:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'u': goto S_679;
	default: last_accepted.second++; return last_accepted;
}

S_679:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'e': goto S_681;
	default: last_accepted.second++; return last_accepted;
}

S_681:
last_accepted = {CONTINUE,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_683:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'e': goto S_685;
	default: last_accepted.second++; return last_accepted;
}

S_685:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'f': goto S_687;
	default: last_accepted.second++; return last_accepted;
}

S_687:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'a': goto S_689;
	default: last_accepted.second++; return last_accepted;
}

S_689:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'u': goto S_691;
	default: last_accepted.second++; return last_accepted;
}

S_691:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'l': goto S_693;
	default: last_accepted.second++; return last_accepted;
}

S_693:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 't': goto S_695;
	default: last_accepted.second++; return last_accepted;
}

S_695:
last_accepted = {DEFAULT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_697:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'o': goto S_699;
	default: last_accepted.second++; return last_accepted;
}

S_699:
last_accepted = {DO,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_701:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'o': goto S_703;
	default: last_accepted.second++; return last_accepted;
}

S_703:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 't': goto S_705;
	default: last_accepted.second++; return last_accepted;
}

S_705:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'o': goto S_707;
	default: last_accepted.second++; return last_accepted;
}

S_707:
last_accepted = {GOTO,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_709:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'w': goto S_711;
	default: last_accepted.second++; return last_accepted;
}

S_711:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'i': goto S_713;
	default: last_accepted.second++; return last_accepted;
}

S_713:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 't': goto S_715;
	default: last_accepted.second++; return last_accepted;
}

S_715:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'c': goto S_717;
	default: last_accepted.second++; return last_accepted;
}

S_717:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'h': goto S_719;
	default: last_accepted.second++; return last_accepted;
}

S_719:
last_accepted = {SWITCH,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_722:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'r': goto S_724;
	default: last_accepted.second++; return last_accepted;
}

S_724:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'u': goto S_726;
	default: last_accepted.second++; return last_accepted;
}

S_726:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'e': goto S_728;
	default: last_accepted.second++; return last_accepted;
}

S_728:
last_accepted = {BOOLEAN_LIT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_730:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'a': goto S_732;
	default: last_accepted.second++; return last_accepted;
}

S_732:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'l': goto S_734;
	default: last_accepted.second++; return last_accepted;
}

S_734:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 's': goto S_736;
	default: last_accepted.second++; return last_accepted;
}

S_736:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'e': goto S_738;
	default: last_accepted.second++; return last_accepted;
}

S_738:
last_accepted = {BOOLEAN_LIT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_740:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'u': goto S_742;
	default: last_accepted.second++; return last_accepted;
}

S_742:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'l': goto S_744;
	default: last_accepted.second++; return last_accepted;
}

S_744:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'l': goto S_746;
	default: last_accepted.second++; return last_accepted;
}

S_746:
last_accepted = {NULL_LIT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_748:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '\n': goto S_1101;
	case '\'': goto S_1101;
	case '\\': goto S_753;
	default: goto S_751;
}

S_751:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '\'': goto S_793;
	default: last_accepted.second++; return last_accepted;
}

S_753:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '\"': goto S_771;
	case '\'': goto S_774;
	case '0': goto S_1103;
	case '1': goto S_1103;
	case '2': goto S_1103;
	case '3': goto S_1103;
	case '4': goto S_1104;
	case '5': goto S_1104;
	case '6': goto S_1104;
	case '7': goto S_1104;
	case '\\': goto S_777;
	case 'b': goto S_756;
	case 'f': goto S_765;
	case 'n': goto S_762;
	case 'r': goto S_768;
	case 't': goto S_759;
	default: last_accepted.second++; return last_accepted;
}

S_756:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '\'': goto S_793;
	default: last_accepted.second++; return last_accepted;
}

S_759:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '\'': goto S_793;
	default: last_accepted.second++; return last_accepted;
}

S_762:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '\'': goto S_793;
	default: last_accepted.second++; return last_accepted;
}

S_765:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '\'': goto S_793;
	default: last_accepted.second++; return last_accepted;
}

S_768:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '\'': goto S_793;
	default: last_accepted.second++; return last_accepted;
}

S_771:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '\'': goto S_793;
	default: last_accepted.second++; return last_accepted;
}

S_774:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '\'': goto S_793;
	default: last_accepted.second++; return last_accepted;
}

S_777:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '\'': goto S_793;
	default: last_accepted.second++; return last_accepted;
}

S_780:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '\'': goto S_793;
	default: last_accepted.second++; return last_accepted;
}

S_783:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '0': goto S_785;
	case '1': goto S_785;
	case '2': goto S_785;
	case '3': goto S_785;
	case '4': goto S_785;
	case '5': goto S_785;
	case '6': goto S_785;
	case '7': goto S_785;
	default: last_accepted.second++; return last_accepted;
}

S_785:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '\'': goto S_793;
	default: last_accepted.second++; return last_accepted;
}

S_787:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '0': goto S_789;
	case '1': goto S_789;
	case '2': goto S_789;
	case '3': goto S_789;
	case '4': goto S_789;
	case '5': goto S_789;
	case '6': goto S_789;
	case '7': goto S_789;
	default: last_accepted.second++; return last_accepted;
}

S_789:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '0': goto S_791;
	case '1': goto S_791;
	case '2': goto S_791;
	case '3': goto S_791;
	case '4': goto S_791;
	case '5': goto S_791;
	case '6': goto S_791;
	case '7': goto S_791;
	default: last_accepted.second++; return last_accepted;
}

S_791:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '\'': goto S_793;
	default: last_accepted.second++; return last_accepted;
}

S_793:
last_accepted = {CHAR_LIT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_795:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '\n': goto S_1101;
	case '\"': goto S_840;
	case '\\': goto S_800;
	default: goto S_798;
}

S_798:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '\n': goto S_1101;
	case '\"': goto S_840;
	case '\\': goto S_800;
	default: goto S_798;
}

S_800:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '\"': goto S_818;
	case '\'': goto S_821;
	case '0': goto S_1106;
	case '1': goto S_1106;
	case '2': goto S_1106;
	case '3': goto S_1106;
	case '4': goto S_1107;
	case '5': goto S_1107;
	case '6': goto S_1107;
	case '7': goto S_1107;
	case '\\': goto S_824;
	case 'b': goto S_803;
	case 'f': goto S_812;
	case 'n': goto S_809;
	case 'r': goto S_815;
	case 't': goto S_806;
	default: last_accepted.second++; return last_accepted;
}

S_803:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '\n': goto S_1101;
	case '\"': goto S_840;
	case '\\': goto S_800;
	default: goto S_798;
}

S_806:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '\n': goto S_1101;
	case '\"': goto S_840;
	case '\\': goto S_800;
	default: goto S_798;
}

S_809:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '\n': goto S_1101;
	case '\"': goto S_840;
	case '\\': goto S_800;
	default: goto S_798;
}

S_812:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '\n': goto S_1101;
	case '\"': goto S_840;
	case '\\': goto S_800;
	default: goto S_798;
}

S_815:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '\n': goto S_1101;
	case '\"': goto S_840;
	case '\\': goto S_800;
	default: goto S_798;
}

S_818:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '\n': goto S_1101;
	case '\"': goto S_840;
	case '\\': goto S_800;
	default: goto S_798;
}

S_821:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '\n': goto S_1101;
	case '\"': goto S_840;
	case '\\': goto S_800;
	default: goto S_798;
}

S_824:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '\n': goto S_1101;
	case '\"': goto S_840;
	case '\\': goto S_800;
	default: goto S_798;
}

S_827:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '\n': goto S_1101;
	case '\"': goto S_840;
	case '\\': goto S_800;
	default: goto S_798;
}

S_830:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '0': goto S_832;
	case '1': goto S_832;
	case '2': goto S_832;
	case '3': goto S_832;
	case '4': goto S_832;
	case '5': goto S_832;
	case '6': goto S_832;
	case '7': goto S_832;
	default: last_accepted.second++; return last_accepted;
}

S_832:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '\n': goto S_1101;
	case '\"': goto S_840;
	case '\\': goto S_800;
	default: goto S_798;
}

S_834:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '0': goto S_836;
	case '1': goto S_836;
	case '2': goto S_836;
	case '3': goto S_836;
	case '4': goto S_836;
	case '5': goto S_836;
	case '6': goto S_836;
	case '7': goto S_836;
	default: last_accepted.second++; return last_accepted;
}

S_836:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '0': goto S_838;
	case '1': goto S_838;
	case '2': goto S_838;
	case '3': goto S_838;
	case '4': goto S_838;
	case '5': goto S_838;
	case '6': goto S_838;
	case '7': goto S_838;
	default: last_accepted.second++; return last_accepted;
}

S_838:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '\n': goto S_1101;
	case '\"': goto S_840;
	case '\\': goto S_800;
	default: goto S_798;
}

S_840:
last_accepted = {STRING_LIT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_844:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '0': goto S_846;
	case '1': goto S_846;
	case '2': goto S_846;
	case '3': goto S_846;
	case '4': goto S_846;
	case '5': goto S_846;
	case '6': goto S_846;
	case '7': goto S_846;
	default: last_accepted.second++; return last_accepted;
}

S_846:
last_accepted = {INT_LIT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '0': goto S_846;
	case '1': goto S_846;
	case '2': goto S_846;
	case '3': goto S_846;
	case '4': goto S_846;
	case '5': goto S_846;
	case '6': goto S_846;
	case '7': goto S_846;
	default: last_accepted.second++; return last_accepted;
}

S_849:
last_accepted = {INT_LIT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_851:
last_accepted = {INT_LIT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '0': goto S_853;
	case '1': goto S_853;
	case '2': goto S_853;
	case '3': goto S_853;
	case '4': goto S_853;
	case '5': goto S_853;
	case '6': goto S_853;
	case '7': goto S_853;
	case '8': goto S_853;
	case '9': goto S_853;
	default: last_accepted.second++; return last_accepted;
}

S_853:
last_accepted = {INT_LIT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '0': goto S_853;
	case '1': goto S_853;
	case '2': goto S_853;
	case '3': goto S_853;
	case '4': goto S_853;
	case '5': goto S_853;
	case '6': goto S_853;
	case '7': goto S_853;
	case '8': goto S_853;
	case '9': goto S_853;
	default: last_accepted.second++; return last_accepted;
}

S_855:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'X': goto S_858;
	case 'x': goto S_860;
	default: last_accepted.second++; return last_accepted;
}

S_858:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '0': goto S_864;
	case '1': goto S_864;
	case '2': goto S_864;
	case '3': goto S_864;
	case '4': goto S_864;
	case '5': goto S_864;
	case '6': goto S_864;
	case '7': goto S_864;
	case '8': goto S_864;
	case '9': goto S_864;
	case 'A': goto S_868;
	case 'B': goto S_868;
	case 'C': goto S_868;
	case 'D': goto S_868;
	case 'E': goto S_868;
	case 'F': goto S_868;
	case 'a': goto S_866;
	case 'b': goto S_866;
	case 'c': goto S_866;
	case 'd': goto S_866;
	case 'e': goto S_866;
	case 'f': goto S_866;
	default: last_accepted.second++; return last_accepted;
}

S_860:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '0': goto S_864;
	case '1': goto S_864;
	case '2': goto S_864;
	case '3': goto S_864;
	case '4': goto S_864;
	case '5': goto S_864;
	case '6': goto S_864;
	case '7': goto S_864;
	case '8': goto S_864;
	case '9': goto S_864;
	case 'A': goto S_868;
	case 'B': goto S_868;
	case 'C': goto S_868;
	case 'D': goto S_868;
	case 'E': goto S_868;
	case 'F': goto S_868;
	case 'a': goto S_866;
	case 'b': goto S_866;
	case 'c': goto S_866;
	case 'd': goto S_866;
	case 'e': goto S_866;
	case 'f': goto S_866;
	default: last_accepted.second++; return last_accepted;
}

S_864:
last_accepted = {INT_LIT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '0': goto S_864;
	case '1': goto S_864;
	case '2': goto S_864;
	case '3': goto S_864;
	case '4': goto S_864;
	case '5': goto S_864;
	case '6': goto S_864;
	case '7': goto S_864;
	case '8': goto S_864;
	case '9': goto S_864;
	case 'A': goto S_868;
	case 'B': goto S_868;
	case 'C': goto S_868;
	case 'D': goto S_868;
	case 'E': goto S_868;
	case 'F': goto S_868;
	case 'a': goto S_866;
	case 'b': goto S_866;
	case 'c': goto S_866;
	case 'd': goto S_866;
	case 'e': goto S_866;
	case 'f': goto S_866;
	default: last_accepted.second++; return last_accepted;
}

S_866:
last_accepted = {INT_LIT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '0': goto S_864;
	case '1': goto S_864;
	case '2': goto S_864;
	case '3': goto S_864;
	case '4': goto S_864;
	case '5': goto S_864;
	case '6': goto S_864;
	case '7': goto S_864;
	case '8': goto S_864;
	case '9': goto S_864;
	case 'A': goto S_868;
	case 'B': goto S_868;
	case 'C': goto S_868;
	case 'D': goto S_868;
	case 'E': goto S_868;
	case 'F': goto S_868;
	case 'a': goto S_866;
	case 'b': goto S_866;
	case 'c': goto S_866;
	case 'd': goto S_866;
	case 'e': goto S_866;
	case 'f': goto S_866;
	default: last_accepted.second++; return last_accepted;
}

S_868:
last_accepted = {INT_LIT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '0': goto S_864;
	case '1': goto S_864;
	case '2': goto S_864;
	case '3': goto S_864;
	case '4': goto S_864;
	case '5': goto S_864;
	case '6': goto S_864;
	case '7': goto S_864;
	case '8': goto S_864;
	case '9': goto S_864;
	case 'A': goto S_868;
	case 'B': goto S_868;
	case 'C': goto S_868;
	case 'D': goto S_868;
	case 'E': goto S_868;
	case 'F': goto S_868;
	case 'a': goto S_866;
	case 'b': goto S_866;
	case 'c': goto S_866;
	case 'd': goto S_866;
	case 'e': goto S_866;
	case 'f': goto S_866;
	default: last_accepted.second++; return last_accepted;
}

S_871:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_874:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_877:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_879:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_882:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_885:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_888:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_891:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_893:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_895:
last_accepted = {ASSIGN,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_897:
last_accepted = {GT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_899:
last_accepted = {LT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_901:
last_accepted = {NOT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_903:
last_accepted = {BITWISE_NOT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_905:
last_accepted = {TERNARY_IF,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_907:
last_accepted = {TERNARY_ELSE,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_909:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '=': goto S_911;
	default: last_accepted.second++; return last_accepted;
}

S_911:
last_accepted = {EQ,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_913:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '=': goto S_915;
	default: last_accepted.second++; return last_accepted;
}

S_915:
last_accepted = {LEQ,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_917:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '=': goto S_919;
	default: last_accepted.second++; return last_accepted;
}

S_919:
last_accepted = {GEQ,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_921:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '=': goto S_923;
	default: last_accepted.second++; return last_accepted;
}

S_923:
last_accepted = {NEQ,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_925:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '&': goto S_927;
	default: last_accepted.second++; return last_accepted;
}

S_927:
last_accepted = {AND,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_929:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '|': goto S_931;
	default: last_accepted.second++; return last_accepted;
}

S_931:
last_accepted = {OR,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_933:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '+': goto S_935;
	default: last_accepted.second++; return last_accepted;
}

S_935:
last_accepted = {INCR,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_937:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '-': goto S_939;
	default: last_accepted.second++; return last_accepted;
}

S_939:
last_accepted = {DECR,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_941:
last_accepted = {PLUS,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_943:
last_accepted = {MINUS,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_945:
last_accepted = {MULT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_947:
last_accepted = {DIV,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_949:
last_accepted = {EAGER_AND,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_951:
last_accepted = {EAGER_OR,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_953:
last_accepted = {XOR,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_955:
last_accepted = {REMAINDER,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_957:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '<': goto S_959;
	default: last_accepted.second++; return last_accepted;
}

S_959:
last_accepted = {LSHIFT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_961:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '>': goto S_963;
	default: last_accepted.second++; return last_accepted;
}

S_963:
last_accepted = {RSHIFT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_965:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '>': goto S_967;
	default: last_accepted.second++; return last_accepted;
}

S_967:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '>': goto S_969;
	default: last_accepted.second++; return last_accepted;
}

S_969:
last_accepted = {UNSIGNED_RSHIFT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_971:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '=': goto S_973;
	default: last_accepted.second++; return last_accepted;
}

S_973:
last_accepted = {PLUS_ASSIGN,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_975:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '=': goto S_977;
	default: last_accepted.second++; return last_accepted;
}

S_977:
last_accepted = {MINUS_ASSIGN,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_979:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '=': goto S_981;
	default: last_accepted.second++; return last_accepted;
}

S_981:
last_accepted = {MULT_ASSIGN,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_983:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '=': goto S_985;
	default: last_accepted.second++; return last_accepted;
}

S_985:
last_accepted = {DIV_ASSIGN,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_987:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '=': goto S_989;
	default: last_accepted.second++; return last_accepted;
}

S_989:
last_accepted = {BITWISE_AND_ASSIGN,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_991:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '=': goto S_993;
	default: last_accepted.second++; return last_accepted;
}

S_993:
last_accepted = {BITWISE_OR_ASSIGN,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_995:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '=': goto S_997;
	default: last_accepted.second++; return last_accepted;
}

S_997:
last_accepted = {BITWISE_XOR_ASSIGN,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_999:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '=': goto S_1001;
	default: last_accepted.second++; return last_accepted;
}

S_1001:
last_accepted = {REMAINDER_ASSIGN,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_1003:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '<': goto S_1005;
	default: last_accepted.second++; return last_accepted;
}

S_1005:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '=': goto S_1007;
	default: last_accepted.second++; return last_accepted;
}

S_1007:
last_accepted = {LSHIFT_ASSIGN,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_1009:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '>': goto S_1011;
	default: last_accepted.second++; return last_accepted;
}

S_1011:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '=': goto S_1013;
	default: last_accepted.second++; return last_accepted;
}

S_1013:
last_accepted = {RSHIFT_ASSIGN,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_1015:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '>': goto S_1017;
	default: last_accepted.second++; return last_accepted;
}

S_1017:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '>': goto S_1019;
	default: last_accepted.second++; return last_accepted;
}

S_1019:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '=': goto S_1021;
	default: last_accepted.second++; return last_accepted;
}

S_1021:
last_accepted = {UNSIGNED_RSHIFT_ASSIGN,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_1022:
last_accepted = {NOT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '=': goto S_923;
	default: last_accepted.second++; return last_accepted;
}

S_1023:
last_accepted = {REMAINDER,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '=': goto S_1001;
	default: last_accepted.second++; return last_accepted;
}

S_1024:
last_accepted = {EAGER_AND,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '&': goto S_927;
	case '=': goto S_989;
	default: last_accepted.second++; return last_accepted;
}

S_1025:
last_accepted = {MULT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '=': goto S_981;
	default: last_accepted.second++; return last_accepted;
}

S_1026:
last_accepted = {PLUS,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '+': goto S_935;
	case '=': goto S_973;
	default: last_accepted.second++; return last_accepted;
}

S_1027:
last_accepted = {MINUS,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '-': goto S_939;
	case '=': goto S_977;
	default: last_accepted.second++; return last_accepted;
}

S_1028:
last_accepted = {DIV,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '*': goto S_125;
	case '/': goto S_117;
	case '=': goto S_985;
	default: last_accepted.second++; return last_accepted;
}

S_1029:
last_accepted = {INT_LIT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '0': goto S_846;
	case '1': goto S_846;
	case '2': goto S_846;
	case '3': goto S_846;
	case '4': goto S_846;
	case '5': goto S_846;
	case '6': goto S_846;
	case '7': goto S_846;
	case 'X': goto S_858;
	case 'x': goto S_860;
	default: last_accepted.second++; return last_accepted;
}

S_1030:
last_accepted = {LT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '<': goto S_1110;
	case '=': goto S_915;
	default: last_accepted.second++; return last_accepted;
}

S_1031:
last_accepted = {ASSIGN,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '=': goto S_911;
	default: last_accepted.second++; return last_accepted;
}

S_1032:
last_accepted = {GT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '=': goto S_919;
	case '>': goto S_1111;
	default: last_accepted.second++; return last_accepted;
}

S_1033:
last_accepted = {LBRACKET,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case ']': goto S_471;
	default: last_accepted.second++; return last_accepted;
}

S_1034:
last_accepted = {XOR,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '=': goto S_997;
	default: last_accepted.second++; return last_accepted;
}

S_1035:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_1112;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1036:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_1113;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_1114;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_1115;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1037:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_1116;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_1117;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_1118;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_1119;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1038:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_1120;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_1121;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1039:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_1122;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_1123;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1040:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_1124;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_1125;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_1126;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_1127;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1041:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_1128;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1042:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_1129;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_1130;
	case 'n': goto S_1131;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1043:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_1132;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1044:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_1133;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_1134;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_1135;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1045:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_1136;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_1137;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_1138;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1046:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_1139;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1047:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_1140;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_1141;
	case 'u': goto S_1142;
	case 'v': goto S_882;
	case 'w': goto S_1143;
	case 'x': goto S_882;
	case 'y': goto S_1144;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1048:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_1145;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_1146;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1049:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_1147;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1050:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_1148;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1051:
last_accepted = {EAGER_OR,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '=': goto S_993;
	case '|': goto S_931;
	default: last_accepted.second++; return last_accepted;
}

S_1052:
last_accepted = {GT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '=': goto S_919;
	case '>': goto S_1149;
	default: last_accepted.second++; return last_accepted;
}

S_1053:
last_accepted = {GT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '=': goto S_919;
	case '>': goto S_1150;
	default: last_accepted.second++; return last_accepted;
}

S_1054:
last_accepted = {LT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '<': goto S_959;
	case '=': goto S_915;
	default: last_accepted.second++; return last_accepted;
}

S_1055:
last_accepted = {EAGER_OR,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '|': goto S_931;
	default: last_accepted.second++; return last_accepted;
}

S_1056:
last_accepted = {EAGER_AND,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '&': goto S_927;
	default: last_accepted.second++; return last_accepted;
}

S_1057:
last_accepted = {DIV,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '*': goto S_125;
	case '/': goto S_117;
	default: last_accepted.second++; return last_accepted;
}

S_1058:
last_accepted = {MINUS,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '-': goto S_939;
	default: last_accepted.second++; return last_accepted;
}

S_1059:
last_accepted = {PLUS,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '+': goto S_935;
	default: last_accepted.second++; return last_accepted;
}

S_1060:
last_accepted = {GT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '=': goto S_919;
	case '>': goto S_963;
	default: last_accepted.second++; return last_accepted;
}

S_1061:
last_accepted = {GT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '=': goto S_919;
	default: last_accepted.second++; return last_accepted;
}

S_1062:
last_accepted = {LT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '=': goto S_915;
	default: last_accepted.second++; return last_accepted;
}

S_1063:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '*': goto S_125;
	case '/': goto S_117;
	default: last_accepted.second++; return last_accepted;
}

S_1064:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'o': goto S_431;
	case 'r': goto S_651;
	case 'y': goto S_453;
	default: last_accepted.second++; return last_accepted;
}

S_1065:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'a': goto S_1151;
	case 'h': goto S_445;
	case 'l': goto S_189;
	case 'o': goto S_1152;
	default: last_accepted.second++; return last_accepted;
}

S_1066:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'e': goto S_685;
	case 'o': goto S_1153;
	default: last_accepted.second++; return last_accepted;
}

S_1067:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'l': goto S_165;
	case 'x': goto S_199;
	default: last_accepted.second++; return last_accepted;
}

S_1068:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'a': goto S_732;
	case 'i': goto S_1154;
	case 'l': goto S_571;
	case 'o': goto S_183;
	default: last_accepted.second++; return last_accepted;
}

S_1069:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'f': goto S_161;
	case 'm': goto S_1155;
	case 'n': goto S_1156;
	default: last_accepted.second++; return last_accepted;
}

S_1070:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'a': goto S_367;
	case 'e': goto S_279;
	case 'u': goto S_742;
	default: last_accepted.second++; return last_accepted;
}

S_1071:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'a': goto S_379;
	case 'r': goto S_1157;
	case 'u': goto S_297;
	default: last_accepted.second++; return last_accepted;
}

S_1072:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'h': goto S_461;
	case 't': goto S_1158;
	case 'u': goto S_641;
	case 'w': goto S_711;
	case 'y': goto S_501;
	default: last_accepted.second++; return last_accepted;
}

S_1073:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'h': goto S_1159;
	case 'r': goto S_1160;
	default: last_accepted.second++; return last_accepted;
}

S_1074:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'o': goto S_1161;
	default: last_accepted.second++; return last_accepted;
}

S_1075:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'a': goto S_367;
	case 'e': goto S_279;
	default: last_accepted.second++; return last_accepted;
}

S_1076:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'i': goto S_1154;
	case 'l': goto S_571;
	case 'o': goto S_183;
	default: last_accepted.second++; return last_accepted;
}

S_1077:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'h': goto S_1159;
	case 'r': goto S_1162;
	default: last_accepted.second++; return last_accepted;
}

S_1078:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'h': goto S_461;
	case 't': goto S_1158;
	case 'u': goto S_641;
	case 'y': goto S_501;
	default: last_accepted.second++; return last_accepted;
}

S_1079:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'e': goto S_685;
	case 'o': goto S_559;
	default: last_accepted.second++; return last_accepted;
}

S_1080:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'a': goto S_1151;
	case 'h': goto S_445;
	case 'l': goto S_189;
	case 'o': goto S_475;
	default: last_accepted.second++; return last_accepted;
}

S_1081:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'a': goto S_589;
	case 'h': goto S_445;
	case 'l': goto S_189;
	case 'o': goto S_475;
	default: last_accepted.second++; return last_accepted;
}

S_1082:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'o': goto S_431;
	case 'y': goto S_453;
	default: last_accepted.second++; return last_accepted;
}

S_1083:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'h': goto S_461;
	case 't': goto S_1158;
	case 'y': goto S_501;
	default: last_accepted.second++; return last_accepted;
}

S_1084:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'h': goto S_1159;
	case 'r': goto S_525;
	default: last_accepted.second++; return last_accepted;
}

S_1085:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'h': goto S_1163;
	case 'r': goto S_525;
	default: last_accepted.second++; return last_accepted;
}

S_1086:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'h': goto S_251;
	case 'r': goto S_525;
	default: last_accepted.second++; return last_accepted;
}

S_1087:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'i': goto S_357;
	case 'l': goto S_571;
	case 'o': goto S_183;
	default: last_accepted.second++; return last_accepted;
}

S_1088:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'h': goto S_445;
	case 'l': goto S_189;
	case 'o': goto S_475;
	default: last_accepted.second++; return last_accepted;
}

S_1089:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'i': goto S_357;
	case 'o': goto S_183;
	default: last_accepted.second++; return last_accepted;
}

S_1090:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'h': goto S_461;
	case 't': goto S_1158;
	default: last_accepted.second++; return last_accepted;
}

S_1091:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'h': goto S_461;
	case 't': goto S_285;
	default: last_accepted.second++; return last_accepted;
}

S_1092:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'h': goto S_445;
	case 'l': goto S_189;
	default: last_accepted.second++; return last_accepted;
}

S_1093:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'f': goto S_161;
	case 'm': goto S_1155;
	case 'n': goto S_1164;
	default: last_accepted.second++; return last_accepted;
}

S_1094:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'f': goto S_161;
	case 'm': goto S_213;
	case 'n': goto S_1164;
	default: last_accepted.second++; return last_accepted;
}

S_1095:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'r': goto S_1157;
	case 'u': goto S_297;
	default: last_accepted.second++; return last_accepted;
}

S_1096:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'r': goto S_309;
	case 'u': goto S_297;
	default: last_accepted.second++; return last_accepted;
}

S_1097:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'f': goto S_161;
	case 'm': goto S_213;
	case 'n': goto S_233;
	default: last_accepted.second++; return last_accepted;
}

S_1098:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'f': goto S_161;
	case 'm': goto S_213;
	default: last_accepted.second++; return last_accepted;
}

S_1099:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '*': goto S_1099;
	case '/': goto S_139;
	default: goto S_131;
}

S_1100:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '*': goto S_1099;
	default: goto S_1100;
}

S_1101:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	default: last_accepted.second++; return last_accepted;
}

S_1102:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '*': goto S_1102;
	case '/': goto S_139;
	default: last_accepted.second++; return last_accepted;
}

S_1103:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '\'': goto S_793;
	case '0': goto S_1165;
	case '1': goto S_1165;
	case '2': goto S_1165;
	case '3': goto S_1165;
	case '4': goto S_1165;
	case '5': goto S_1165;
	case '6': goto S_1165;
	case '7': goto S_1165;
	default: last_accepted.second++; return last_accepted;
}

S_1104:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '\'': goto S_793;
	case '0': goto S_785;
	case '1': goto S_785;
	case '2': goto S_785;
	case '3': goto S_785;
	case '4': goto S_785;
	case '5': goto S_785;
	case '6': goto S_785;
	case '7': goto S_785;
	default: last_accepted.second++; return last_accepted;
}

S_1105:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '0': goto S_1165;
	case '1': goto S_1165;
	case '2': goto S_1165;
	case '3': goto S_1165;
	case '4': goto S_1165;
	case '5': goto S_1165;
	case '6': goto S_1165;
	case '7': goto S_1165;
	default: last_accepted.second++; return last_accepted;
}

S_1106:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '\n': goto S_1101;
	case '\"': goto S_840;
	case '0': goto S_1166;
	case '1': goto S_1166;
	case '2': goto S_1166;
	case '3': goto S_1166;
	case '4': goto S_1166;
	case '5': goto S_1166;
	case '6': goto S_1166;
	case '7': goto S_1166;
	case '\\': goto S_800;
	default: goto S_798;
}

S_1107:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '\n': goto S_1101;
	case '\"': goto S_840;
	case '0': goto S_832;
	case '1': goto S_832;
	case '2': goto S_832;
	case '3': goto S_832;
	case '4': goto S_832;
	case '5': goto S_832;
	case '6': goto S_832;
	case '7': goto S_832;
	case '\\': goto S_800;
	default: goto S_798;
}

S_1108:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '0': goto S_1166;
	case '1': goto S_1166;
	case '2': goto S_1166;
	case '3': goto S_1166;
	case '4': goto S_1166;
	case '5': goto S_1166;
	case '6': goto S_1166;
	case '7': goto S_1166;
	default: last_accepted.second++; return last_accepted;
}

S_1109:
last_accepted = {INT_LIT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '0': goto S_846;
	case '1': goto S_846;
	case '2': goto S_846;
	case '3': goto S_846;
	case '4': goto S_846;
	case '5': goto S_846;
	case '6': goto S_846;
	case '7': goto S_846;
	default: last_accepted.second++; return last_accepted;
}

S_1110:
last_accepted = {LSHIFT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '=': goto S_1007;
	default: last_accepted.second++; return last_accepted;
}

S_1111:
last_accepted = {RSHIFT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '=': goto S_1013;
	case '>': goto S_1167;
	default: last_accepted.second++; return last_accepted;
}

S_1112:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_1168;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1113:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_1169;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1114:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_1170;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1115:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_1171;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1116:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_1172;
	case 't': goto S_1173;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1117:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_1174;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1118:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_1175;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1119:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_1176;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1120:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_1177;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1121:
last_accepted = {DO,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_1178;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1122:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_1179;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1123:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_1180;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1124:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_1181;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1125:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_1182;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1126:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_1183;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1127:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_1184;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1128:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_1185;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1129:
last_accepted = {IF,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1130:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_1186;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1131:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_1187;
	case 't': goto S_1188;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1132:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_1189;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1133:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_1190;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1134:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_1191;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1135:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_1192;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1136:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_1193;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1137:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_1194;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_1195;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1138:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_1196;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1139:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_1197;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1140:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_1198;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1141:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_1199;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_1200;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1142:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_1201;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1143:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_1202;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1144:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_1203;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1145:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_1204;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_1205;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1146:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_1206;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_1207;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_1208;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1147:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_1209;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_1210;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1148:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_1211;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1149:
last_accepted = {RSHIFT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '=': goto S_1013;
	case '>': goto S_969;
	default: last_accepted.second++; return last_accepted;
}

S_1150:
last_accepted = {RSHIFT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '>': goto S_969;
	default: last_accepted.second++; return last_accepted;
}

S_1151:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 's': goto S_663;
	case 't': goto S_591;
	default: last_accepted.second++; return last_accepted;
}

S_1152:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'n': goto S_1212;
	default: last_accepted.second++; return last_accepted;
}

S_1153:
last_accepted = {DO,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'u': goto S_561;
	default: last_accepted.second++; return last_accepted;
}

S_1154:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'n': goto S_1213;
	default: last_accepted.second++; return last_accepted;
}

S_1155:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'p': goto S_1214;
	default: last_accepted.second++; return last_accepted;
}

S_1156:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 's': goto S_261;
	case 't': goto S_1215;
	default: last_accepted.second++; return last_accepted;
}

S_1157:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'i': goto S_311;
	case 'o': goto S_325;
	default: last_accepted.second++; return last_accepted;
}

S_1158:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'a': goto S_287;
	case 'r': goto S_487;
	default: last_accepted.second++; return last_accepted;
}

S_1159:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'i': goto S_253;
	case 'r': goto S_1216;
	default: last_accepted.second++; return last_accepted;
}

S_1160:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'a': goto S_527;
	case 'u': goto S_726;
	case 'y': goto S_637;
	default: last_accepted.second++; return last_accepted;
}

S_1161:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'i': goto S_419;
	case 'l': goto S_545;
	default: last_accepted.second++; return last_accepted;
}

S_1162:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'a': goto S_527;
	case 'y': goto S_637;
	default: last_accepted.second++; return last_accepted;
}

S_1163:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'i': goto S_253;
	case 'r': goto S_615;
	default: last_accepted.second++; return last_accepted;
}

S_1164:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 's': goto S_261;
	case 't': goto S_235;
	default: last_accepted.second++; return last_accepted;
}

S_1165:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '\'': goto S_793;
	case '0': goto S_791;
	case '1': goto S_791;
	case '2': goto S_791;
	case '3': goto S_791;
	case '4': goto S_791;
	case '5': goto S_791;
	case '6': goto S_791;
	case '7': goto S_791;
	default: last_accepted.second++; return last_accepted;
}

S_1166:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '\n': goto S_1101;
	case '\"': goto S_840;
	case '0': goto S_838;
	case '1': goto S_838;
	case '2': goto S_838;
	case '3': goto S_838;
	case '4': goto S_838;
	case '5': goto S_838;
	case '6': goto S_838;
	case '7': goto S_838;
	case '\\': goto S_800;
	default: goto S_798;
}

S_1167:
last_accepted = {UNSIGNED_RSHIFT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '=': goto S_1021;
	default: last_accepted.second++; return last_accepted;
}

S_1168:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_1217;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1169:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_1218;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1170:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_1219;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1171:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_1220;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1172:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_1221;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1173:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_1222;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1174:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_1223;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1175:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_1224;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1176:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_1225;
	case 't': goto S_1226;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1177:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_1227;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1178:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_1228;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1179:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_1229;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1180:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_1230;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1181:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_1231;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1182:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_1232;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1183:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_1233;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1184:
last_accepted = {FOR,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1185:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_1234;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1186:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_1235;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_1236;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1187:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_1237;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1188:
last_accepted = {INT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_1238;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1189:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_1239;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1190:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_1240;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1191:
last_accepted = {NEW,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1192:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_1241;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1193:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_1242;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1194:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_1243;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1195:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_1244;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1196:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_1245;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1197:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_1246;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1198:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_1247;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1199:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_1248;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1200:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_1249;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1201:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_1250;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1202:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_1251;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1203:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_1252;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1204:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_1253;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1205:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_1254;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1206:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_1255;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1207:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_1256;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1208:
last_accepted = {TRY,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1209:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_1257;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1210:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_1258;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1211:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_1259;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1212:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 's': goto S_479;
	case 't': goto S_673;
	default: last_accepted.second++; return last_accepted;
}

S_1213:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'a': goto S_1260;
	default: last_accepted.second++; return last_accepted;
}

S_1214:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'l': goto S_217;
	case 'o': goto S_397;
	default: last_accepted.second++; return last_accepted;
}

S_1215:
last_accepted = {INT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'e': goto S_237;
	default: last_accepted.second++; return last_accepted;
}

S_1216:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'o': goto S_1261;
	default: last_accepted.second++; return last_accepted;
}

S_1217:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_1262;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1218:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_1263;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1219:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_1264;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1220:
last_accepted = {BYTE,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1221:
last_accepted = {CASE,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1222:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_1265;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1223:
last_accepted = {CHAR,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1224:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_1266;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1225:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_1267;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1226:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_1268;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1227:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_1269;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1228:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_1270;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1229:
last_accepted = {ELSE,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1230:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_1271;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1231:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_1272;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1232:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_1273;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1233:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_1274;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1234:
last_accepted = {GOTO,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1235:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_1275;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1236:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_1276;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1237:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_1277;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1238:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_1278;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1239:
last_accepted = {LONG,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1240:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_1279;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1241:
last_accepted = {NULL_LIT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1242:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_1280;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1243:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_1281;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1244:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_1282;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1245:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_1283;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1246:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_1284;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1247:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_1285;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1248:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_1286;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1249:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_1287;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1250:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_1288;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1251:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_1289;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1252:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_1290;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1253:
last_accepted = {THIS,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1254:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_1291;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1255:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_1292;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1256:
last_accepted = {BOOLEAN_LIT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1257:
last_accepted = {VOID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1258:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_1293;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1259:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_1294;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1260:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'l': goto S_1295;
	default: last_accepted.second++; return last_accepted;
}

S_1261:
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'w': goto S_1296;
	default: last_accepted.second++; return last_accepted;
}

S_1262:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_1297;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1263:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_1298;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1264:
last_accepted = {BREAK,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1265:
last_accepted = {CATCH,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1266:
last_accepted = {CLASS,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1267:
last_accepted = {CONST,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1268:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_1299;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1269:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_1300;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1270:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_1301;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1271:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_1302;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1272:
last_accepted = {BOOLEAN_LIT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1273:
last_accepted = {FINAL,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_1303;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1274:
last_accepted = {FLOAT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1275:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_1304;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1276:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_1305;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1277:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_1306;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1278:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_1307;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1279:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_1308;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1280:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_1309;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1281:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_1310;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1282:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_1311;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1283:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_1312;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1284:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_1313;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1285:
last_accepted = {SHORT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1286:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_1314;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1287:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_1315;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1288:
last_accepted = {SUPER,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1289:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_1316;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1290:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_1317;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1291:
last_accepted = {THROW,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_1318;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1292:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_1319;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1293:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_1320;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1294:
last_accepted = {WHILE,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1295:
last_accepted = {FINAL,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 'l': goto S_607;
	default: last_accepted.second++; return last_accepted;
}

S_1296:
last_accepted = {THROW,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case 's': goto S_631;
	default: last_accepted.second++; return last_accepted;
}

S_1297:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_1321;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1298:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_1322;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1299:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_1323;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1300:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_1324;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1301:
last_accepted = {DOUBLE,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1302:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_1325;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1303:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_1326;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1304:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_1327;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1305:
last_accepted = {IMPORT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1306:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_1328;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1307:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_1329;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1308:
last_accepted = {NATIVE,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1309:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_1330;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1310:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_1331;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1311:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_1332;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1312:
last_accepted = {PUBLIC,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1313:
last_accepted = {RETURN,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1314:
last_accepted = {STATIC,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1315:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_1333;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1316:
last_accepted = {SWITCH,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1317:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_1334;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1318:
last_accepted = {THROWS,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1319:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_1335;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1320:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_1336;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1321:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_1337;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1322:
last_accepted = {BOOLEAN,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1323:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_1338;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1324:
last_accepted = {DEFAULT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1325:
last_accepted = {EXTENDS,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1326:
last_accepted = {FINALLY,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1327:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_1339;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1328:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_1340;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1329:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_1341;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1330:
last_accepted = {PACKAGE,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1331:
last_accepted = {PRIVATE,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1332:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_1342;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1333:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_1343;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1334:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_1344;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1335:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_1345;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1336:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_1346;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1337:
last_accepted = {ABSTRACT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1338:
last_accepted = {CONTINUE,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1339:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_1347;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1340:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_1348;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1341:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_1349;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1342:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_1350;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1343:
last_accepted = {STRICTFP,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1344:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_1351;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1345:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_1352;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1346:
last_accepted = {VOLATILE,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1347:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_1353;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1348:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_1354;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1349:
last_accepted = {INTERFACE,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1350:
last_accepted = {PROTECTED,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1351:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_1355;
	default: last_accepted.second++; return last_accepted;
}

S_1352:
last_accepted = {TRANSIENT,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1353:
last_accepted = {IMPLEMENTS,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1354:
last_accepted = {INSTANCEOF,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1355:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_1356;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1356:
last_accepted = {ID,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_1357;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

S_1357:
last_accepted = {SYNCHRONIZED,start};
start++;
if(start >= s.size()) { last_accepted.second++; return last_accepted; }
switch(s[start])
{
	case '$': goto S_888;
	case '0': goto S_893;
	case '1': goto S_893;
	case '2': goto S_893;
	case '3': goto S_893;
	case '4': goto S_893;
	case '5': goto S_893;
	case '6': goto S_893;
	case '7': goto S_893;
	case '8': goto S_893;
	case '9': goto S_893;
	case 'A': goto S_885;
	case 'B': goto S_885;
	case 'C': goto S_885;
	case 'D': goto S_885;
	case 'E': goto S_885;
	case 'F': goto S_885;
	case 'G': goto S_885;
	case 'H': goto S_885;
	case 'I': goto S_885;
	case 'J': goto S_885;
	case 'K': goto S_885;
	case 'L': goto S_885;
	case 'M': goto S_885;
	case 'N': goto S_885;
	case 'O': goto S_885;
	case 'P': goto S_885;
	case 'Q': goto S_885;
	case 'R': goto S_885;
	case 'S': goto S_885;
	case 'T': goto S_885;
	case 'U': goto S_885;
	case 'V': goto S_885;
	case 'W': goto S_885;
	case 'X': goto S_885;
	case 'Y': goto S_885;
	case 'Z': goto S_885;
	case '_': goto S_891;
	case 'a': goto S_882;
	case 'b': goto S_882;
	case 'c': goto S_882;
	case 'd': goto S_882;
	case 'e': goto S_882;
	case 'f': goto S_882;
	case 'g': goto S_882;
	case 'h': goto S_882;
	case 'i': goto S_882;
	case 'j': goto S_882;
	case 'k': goto S_882;
	case 'l': goto S_882;
	case 'm': goto S_882;
	case 'n': goto S_882;
	case 'o': goto S_882;
	case 'p': goto S_882;
	case 'q': goto S_882;
	case 'r': goto S_882;
	case 's': goto S_882;
	case 't': goto S_882;
	case 'u': goto S_882;
	case 'v': goto S_882;
	case 'w': goto S_882;
	case 'x': goto S_882;
	case 'y': goto S_882;
	case 'z': goto S_882;
	default: last_accepted.second++; return last_accepted;
}

}
