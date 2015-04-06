#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <queue>
#include <sstream>

class Solution {
    typedef std::vector<std::string> Result;
    typedef std::vector<Result>      ResultList;
    typedef std::unordered_map<std::string, ResultList> Cache;

    Cache d_cache;

    /*
    void helper(ResultList                             *resultList,
                Result                                 *result,
                std::unordered_set<std::string>        *visited,
                const std::string&                      start,
                const std::string&                      end,
                const std::unordered_set<std::string>&  dict,
                int                                     depth,
                int                                     maxDepth)
    {
        if (depth >= maxDepth) {
            return;
        }
        for (int i = 0; i < start.size(); ++i) {
            for (char c = 'a'; c <= 'z'; ++c) {
                if (start[i] != c) {
                    std::string next = start;
                    next[i] = c;
                    if (next == end
                    ||  (1 == dict.count(next) && 0 == visited->count(next)))
                    {
                        result->push_back(next);
                        if (next == end) {
                            resultList->push_back(*result);
                            result->pop_back();
                            continue;
                        }
                        visited->insert(next);

                        Cache::const_iterator it = d_cache.find(next);
                        if (d_cache.end() != it) {

                        helper(resultList, result, visited, next, end, dict,
                               depth + 1, maxDepth);
                        d_cache.insert(std::make_pair(next, *resultList));
                        visited->erase(next);
                        result->pop_back();
                    }
                }
            }
        }
    }
    */

    ResultList helper(std::unordered_set<std::string>        *visited,
                      const std::string&                      start,
                      const std::string&                      end,
                      const std::unordered_set<std::string>&  dict,
                      int                                     depth,
                      int                                     maxDepth)
    {
//        for (int i = 0; i < depth; ++i) {
//            std::cout << "    ";
//        }
//        std::cout << start << "|" << end << "|" << depth
//                  << "|" << maxDepth << std::endl;

        ResultList currList;

        if (depth >= maxDepth) {
//            std::cout << "BAD" << std::endl;
            return currList;
        }

        std::ostringstream oss;
        oss << start << depth;
        std::string key = oss.str();

        if (start == end) {
//            std::cout << "MATCH" << std::endl;
            currList.push_back(Result(1, start));
            d_cache.insert(std::make_pair(key, currList));
            return currList;
        }

        Cache::const_iterator it = d_cache.find(key);
        if (d_cache.end() != it) {
//            std::cout << "CACHED" << std::endl;
            return it->second;
        }

        for (int i = 0; i < start.size(); ++i) {
            for (char c = 'a'; c <= 'z'; ++c) {
                if (start[i] != c) {
                    std::string next = start;
                    next[i] = c;

                    if ((next == end)
                     || (1 == dict.count(next) && 0 == visited->count(next)))
                    {
                        //visited->insert(next);
                        ResultList nextList = helper(visited, next, end, dict,
                                              depth + 1, maxDepth);
                        //visited->erase(next);

                        if (nextList.empty()) {
                            continue;
                        }
                        for (int i = 0; i < nextList.size(); ++i) {
                            nextList[i].push_back(start);
                        }
                        currList.insert(currList.end(),
                                        nextList.begin(),
                                        nextList.end());
                    }
                }
            }
        }
        if (!currList.empty()) {
//            std::cout << start << "-" << currList.size() << std::endl;
            d_cache.insert(std::make_pair(key, currList));
        }
        return currList;
    }

    int ladderLength(const std::string&                     start,
                     const std::string&                     end,
                     const std::unordered_set<std::string>& dict)
    {
        std::unordered_set<std::string> newDict;

        // We use BFS to traverse the space to get the minimum depth first.

        if (start == end) {
            return 1;
        }
        int depth = 2;
        std::queue<std::string>         queue;
        std::unordered_set<std::string> visited;
        queue.push(start);
        visited.insert(start);
        int numCurr = 1; // number of nodes at the current level
        int numNext = 0; // number of children nodes at the next level
        while (!queue.empty()) {
            std::string word = queue.front();
            queue.pop();
            --numCurr;
            for (int i = 0; i < word.size(); ++i) {
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (word[i] != c) {
                        std::string next = word;
                        next[i] = c;
                        if (next == end) {
                            return depth;
                        }
                        // check if the node is in the dictionary and not
                        // visited.
                        if (1 == dict.count(next) && 0 == visited.count(next))
                        {
                            queue.push(next);
                            visited.insert(next);
                            ++numNext;
                        }
                    }
                }
            }
            if (0 == numCurr) {
                // we have visited all the nodes at the current level, and we
                // will start visiting the nodes at the next level.
                numCurr = numNext;
                numNext = 0;
                ++depth;
            }
        }
        return 0;
    }

  public:
    std::vector<std::vector<std::string> > findLadders(
            const std::string&                     start,
            const std::string&                     end,
            const std::unordered_set<std::string>& dict)
    {
        int maxDepth = ladderLength(start, end, dict);
        std::cout << maxDepth << std::endl;

        ResultList                      resultList;
        Result                          result;
        std::unordered_set<std::string> visited;
        //helper(&resultList, &result, &visited, start, end, dict,
        //       0, maxDepth - 1);
        //
        //return resultList;
        return helper(&visited, start, end, dict, 0, maxDepth);
    }
};

void print(const std::vector<std::vector<std::string> >& value)
{
    for (int i = 0; i < value.size(); ++i) {
        for (int j = 0; j < value[i].size(); ++j) {
            std::cout << value[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    {
        std::unordered_set<std::string> dict;
        dict.insert("hot");
        dict.insert("dot");
        dict.insert("dog");
        dict.insert("lot");
        dict.insert("log");

        Solution s;
        print(s.findLadders("hit", "cog", dict));
    }

    {
        std::unordered_set<std::string> dict;
        dict.insert("hot");
        dict.insert("dog");
        dict.insert("dot");

        Solution s;
        print(s.findLadders("hot", "dog", dict));
    }

    {
        std::unordered_set<std::string> dict;
        dict.insert("ted");
        dict.insert("tex");
        dict.insert("red");
        dict.insert("tax");
        dict.insert("tad");
        dict.insert("den");
        dict.insert("rex");
        dict.insert("pee");

        Solution s;
        print(s.findLadders("red", "tax", dict));
    }

    {
        std::unordered_set<std::string> dict;
        dict.insert("si");
        dict.insert("go");
        dict.insert("se");
        dict.insert("cm");
        dict.insert("so");
        dict.insert("ph");
        dict.insert("mt");
        dict.insert("db");
        dict.insert("mb");
        dict.insert("sb");
        dict.insert("kr");
        dict.insert("ln");
        dict.insert("tm");
        dict.insert("le");
        dict.insert("av");
        dict.insert("sm");
        dict.insert("ar");
        dict.insert("ci");
        dict.insert("ca");
        dict.insert("br");
        dict.insert("ti");
        dict.insert("ba");
        dict.insert("to");
        dict.insert("ra");
        dict.insert("fa");
        dict.insert("yo");
        dict.insert("ow");
        dict.insert("sn");
        dict.insert("ya");
        dict.insert("cr");
        dict.insert("po");
        dict.insert("fe");
        dict.insert("ho");
        dict.insert("ma");
        dict.insert("re");
        dict.insert("or");
        dict.insert("rn");
        dict.insert("au");
        dict.insert("ur");
        dict.insert("rh");
        dict.insert("sr");
        dict.insert("tc");
        dict.insert("lt");
        dict.insert("lo");
        dict.insert("as");
        dict.insert("fr");
        dict.insert("nb");
        dict.insert("yb");
        dict.insert("if");
        dict.insert("pb");
        dict.insert("ge");
        dict.insert("th");
        dict.insert("pm");
        dict.insert("rb");
        dict.insert("sh");
        dict.insert("co");
        dict.insert("ga");
        dict.insert("li");
        dict.insert("ha");
        dict.insert("hz");
        dict.insert("no");
        dict.insert("bi");
        dict.insert("di");
        dict.insert("hi");
        dict.insert("qa");
        dict.insert("pi");
        dict.insert("os");
        dict.insert("uh");
        dict.insert("wm");
        dict.insert("an");
        dict.insert("me");
        dict.insert("mo");
        dict.insert("na");
        dict.insert("la");
        dict.insert("st");
        dict.insert("er");
        dict.insert("sc");
        dict.insert("ne");
        dict.insert("mn");
        dict.insert("mi");
        dict.insert("am");
        dict.insert("ex");
        dict.insert("pt");
        dict.insert("io");
        dict.insert("be");
        dict.insert("fm");
        dict.insert("ta");
        dict.insert("tb");
        dict.insert("ni");
        dict.insert("mr");
        dict.insert("pa");
        dict.insert("he");
        dict.insert("lr");
        dict.insert("sq");
        dict.insert("ye");

        Solution s;
        print(s.findLadders("qa", "sq", dict));
    }

    {
        std::unordered_set<std::string> dict;
        dict.insert("kid");
        dict.insert("tag");
        dict.insert("pup");
        dict.insert("ail");
        dict.insert("tun");
        dict.insert("woo");
        dict.insert("erg");
        dict.insert("luz");
        dict.insert("brr");
        dict.insert("gay");
        dict.insert("sip");
        dict.insert("kay");
        dict.insert("per");
        dict.insert("val");
        dict.insert("mes");
        dict.insert("ohs");
        dict.insert("now");
        dict.insert("boa");
        dict.insert("cet");
        dict.insert("pal");
        dict.insert("bar");
        dict.insert("die");
        dict.insert("war");
        dict.insert("hay");
        dict.insert("eco");
        dict.insert("pub");
        dict.insert("lob");
        dict.insert("rue");
        dict.insert("fry");
        dict.insert("lit");
        dict.insert("rex");
        dict.insert("jan");
        dict.insert("cot");
        dict.insert("bid");
        dict.insert("ali");
        dict.insert("pay");
        dict.insert("col");
        dict.insert("gum");
        dict.insert("ger");
        dict.insert("row");
        dict.insert("won");
        dict.insert("dan");
        dict.insert("rum");
        dict.insert("fad");
        dict.insert("tut");
        dict.insert("sag");
        dict.insert("yip");
        dict.insert("sui");
        dict.insert("ark");
        dict.insert("has");
        dict.insert("zip");
        dict.insert("fez");
        dict.insert("own");
        dict.insert("ump");
        dict.insert("dis");
        dict.insert("ads");
        dict.insert("max");
        dict.insert("jaw");
        dict.insert("out");
        dict.insert("btu");
        dict.insert("ana");
        dict.insert("gap");
        dict.insert("cry");
        dict.insert("led");
        dict.insert("abe");
        dict.insert("box");
        dict.insert("ore");
        dict.insert("pig");
        dict.insert("fie");
        dict.insert("toy");
        dict.insert("fat");
        dict.insert("cal");
        dict.insert("lie");
        dict.insert("noh");
        dict.insert("sew");
        dict.insert("ono");
        dict.insert("tam");
        dict.insert("flu");
        dict.insert("mgm");
        dict.insert("ply");
        dict.insert("awe");
        dict.insert("pry");
        dict.insert("tit");
        dict.insert("tie");
        dict.insert("yet");
        dict.insert("too");
        dict.insert("tax");
        dict.insert("jim");
        dict.insert("san");
        dict.insert("pan");
        dict.insert("map");
        dict.insert("ski");
        dict.insert("ova");
        dict.insert("wed");
        dict.insert("non");
        dict.insert("wac");
        dict.insert("nut");
        dict.insert("why");
        dict.insert("bye");
        dict.insert("lye");
        dict.insert("oct");
        dict.insert("old");
        dict.insert("fin");
        dict.insert("feb");
        dict.insert("chi");
        dict.insert("sap");
        dict.insert("owl");
        dict.insert("log");
        dict.insert("tod");
        dict.insert("dot");
        dict.insert("bow");
        dict.insert("fob");
        dict.insert("for");
        dict.insert("joe");
        dict.insert("ivy");
        dict.insert("fan");
        dict.insert("age");
        dict.insert("fax");
        dict.insert("hip");
        dict.insert("jib");
        dict.insert("mel");
        dict.insert("hus");
        dict.insert("sob");
        dict.insert("ifs");
        dict.insert("tab");
        dict.insert("ara");
        dict.insert("dab");
        dict.insert("jag");
        dict.insert("jar");
        dict.insert("arm");
        dict.insert("lot");
        dict.insert("tom");
        dict.insert("sax");
        dict.insert("tex");
        dict.insert("yum");
        dict.insert("pei");
        dict.insert("wen");
        dict.insert("wry");
        dict.insert("ire");
        dict.insert("irk");
        dict.insert("far");
        dict.insert("mew");
        dict.insert("wit");
        dict.insert("doe");
        dict.insert("gas");
        dict.insert("rte");
        dict.insert("ian");
        dict.insert("pot");
        dict.insert("ask");
        dict.insert("wag");
        dict.insert("hag");
        dict.insert("amy");
        dict.insert("nag");
        dict.insert("ron");
        dict.insert("soy");
        dict.insert("gin");
        dict.insert("don");
        dict.insert("tug");
        dict.insert("fay");
        dict.insert("vic");
        dict.insert("boo");
        dict.insert("nam");
        dict.insert("ave");
        dict.insert("buy");
        dict.insert("sop");
        dict.insert("but");
        dict.insert("orb");
        dict.insert("fen");
        dict.insert("paw");
        dict.insert("his");
        dict.insert("sub");
        dict.insert("bob");
        dict.insert("yea");
        dict.insert("oft");
        dict.insert("inn");
        dict.insert("rod");
        dict.insert("yam");
        dict.insert("pew");
        dict.insert("web");
        dict.insert("hod");
        dict.insert("hun");
        dict.insert("gyp");
        dict.insert("wei");
        dict.insert("wis");
        dict.insert("rob");
        dict.insert("gad");
        dict.insert("pie");
        dict.insert("mon");
        dict.insert("dog");
        dict.insert("bib");
        dict.insert("rub");
        dict.insert("ere");
        dict.insert("dig");
        dict.insert("era");
        dict.insert("cat");
        dict.insert("fox");
        dict.insert("bee");
        dict.insert("mod");
        dict.insert("day");
        dict.insert("apr");
        dict.insert("vie");
        dict.insert("nev");
        dict.insert("jam");
        dict.insert("pam");
        dict.insert("new");
        dict.insert("aye");
        dict.insert("ani");
        dict.insert("and");
        dict.insert("ibm");
        dict.insert("yap");
        dict.insert("can");
        dict.insert("pyx");
        dict.insert("tar");
        dict.insert("kin");
        dict.insert("fog");
        dict.insert("hum");
        dict.insert("pip");
        dict.insert("cup");
        dict.insert("dye");
        dict.insert("lyx");
        dict.insert("jog");
        dict.insert("nun");
        dict.insert("par");
        dict.insert("wan");
        dict.insert("fey");
        dict.insert("bus");
        dict.insert("oak");
        dict.insert("bad");
        dict.insert("ats");
        dict.insert("set");
        dict.insert("qom");
        dict.insert("vat");
        dict.insert("eat");
        dict.insert("pus");
        dict.insert("rev");
        dict.insert("axe");
        dict.insert("ion");
        dict.insert("six");
        dict.insert("ila");
        dict.insert("lao");
        dict.insert("mom");
        dict.insert("mas");
        dict.insert("pro");
        dict.insert("few");
        dict.insert("opt");
        dict.insert("poe");
        dict.insert("art");
        dict.insert("ash");
        dict.insert("oar");
        dict.insert("cap");
        dict.insert("lop");
        dict.insert("may");
        dict.insert("shy");
        dict.insert("rid");
        dict.insert("bat");
        dict.insert("sum");
        dict.insert("rim");
        dict.insert("fee");
        dict.insert("bmw");
        dict.insert("sky");
        dict.insert("maj");
        dict.insert("hue");
        dict.insert("thy");
        dict.insert("ava");
        dict.insert("rap");
        dict.insert("den");
        dict.insert("fla");
        dict.insert("auk");
        dict.insert("cox");
        dict.insert("ibo");
        dict.insert("hey");
        dict.insert("saw");
        dict.insert("vim");
        dict.insert("sec");
        dict.insert("ltd");
        dict.insert("you");
        dict.insert("its");
        dict.insert("tat");
        dict.insert("dew");
        dict.insert("eva");
        dict.insert("tog");
        dict.insert("ram");
        dict.insert("let");
        dict.insert("see");
        dict.insert("zit");
        dict.insert("maw");
        dict.insert("nix");
        dict.insert("ate");
        dict.insert("gig");
        dict.insert("rep");
        dict.insert("owe");
        dict.insert("ind");
        dict.insert("hog");
        dict.insert("eve");
        dict.insert("sam");
        dict.insert("zoo");
        dict.insert("any");
        dict.insert("dow");
        dict.insert("cod");
        dict.insert("bed");
        dict.insert("vet");
        dict.insert("ham");
        dict.insert("sis");
        dict.insert("hex");
        dict.insert("via");
        dict.insert("fir");
        dict.insert("nod");
        dict.insert("mao");
        dict.insert("aug");
        dict.insert("mum");
        dict.insert("hoe");
        dict.insert("bah");
        dict.insert("hal");
        dict.insert("keg");
        dict.insert("hew");
        dict.insert("zed");
        dict.insert("tow");
        dict.insert("gog");
        dict.insert("ass");
        dict.insert("dem");
        dict.insert("who");
        dict.insert("bet");
        dict.insert("gos");
        dict.insert("son");
        dict.insert("ear");
        dict.insert("spy");
        dict.insert("kit");
        dict.insert("boy");
        dict.insert("due");
        dict.insert("sen");
        dict.insert("oaf");
        dict.insert("mix");
        dict.insert("hep");
        dict.insert("fur");
        dict.insert("ada");
        dict.insert("bin");
        dict.insert("nil");
        dict.insert("mia");
        dict.insert("ewe");
        dict.insert("hit");
        dict.insert("fix");
        dict.insert("sad");
        dict.insert("rib");
        dict.insert("eye");
        dict.insert("hop");
        dict.insert("haw");
        dict.insert("wax");
        dict.insert("mid");
        dict.insert("tad");
        dict.insert("ken");
        dict.insert("wad");
        dict.insert("rye");
        dict.insert("pap");
        dict.insert("bog");
        dict.insert("gut");
        dict.insert("ito");
        dict.insert("woe");
        dict.insert("our");
        dict.insert("ado");
        dict.insert("sin");
        dict.insert("mad");
        dict.insert("ray");
        dict.insert("hon");
        dict.insert("roy");
        dict.insert("dip");
        dict.insert("hen");
        dict.insert("iva");
        dict.insert("lug");
        dict.insert("asp");
        dict.insert("hui");
        dict.insert("yak");
        dict.insert("bay");
        dict.insert("poi");
        dict.insert("yep");
        dict.insert("bun");
        dict.insert("try");
        dict.insert("lad");
        dict.insert("elm");
        dict.insert("nat");
        dict.insert("wyo");
        dict.insert("gym");
        dict.insert("dug");
        dict.insert("toe");
        dict.insert("dee");
        dict.insert("wig");
        dict.insert("sly");
        dict.insert("rip");
        dict.insert("geo");
        dict.insert("cog");
        dict.insert("pas");
        dict.insert("zen");
        dict.insert("odd");
        dict.insert("nan");
        dict.insert("lay");
        dict.insert("pod");
        dict.insert("fit");
        dict.insert("hem");
        dict.insert("joy");
        dict.insert("bum");
        dict.insert("rio");
        dict.insert("yon");
        dict.insert("dec");
        dict.insert("leg");
        dict.insert("put");
        dict.insert("sue");
        dict.insert("dim");
        dict.insert("pet");
        dict.insert("yaw");
        dict.insert("nub");
        dict.insert("bit");
        dict.insert("bur");
        dict.insert("sid");
        dict.insert("sun");
        dict.insert("oil");
        dict.insert("red");
        dict.insert("doc");
        dict.insert("moe");
        dict.insert("caw");
        dict.insert("eel");
        dict.insert("dix");
        dict.insert("cub");
        dict.insert("end");
        dict.insert("gem");
        dict.insert("off");
        dict.insert("yew");
        dict.insert("hug");
        dict.insert("pop");
        dict.insert("tub");
        dict.insert("sgt");
        dict.insert("lid");
        dict.insert("pun");
        dict.insert("ton");
        dict.insert("sol");
        dict.insert("din");
        dict.insert("yup");
        dict.insert("jab");
        dict.insert("pea");
        dict.insert("bug");
        dict.insert("gag");
        dict.insert("mil");
        dict.insert("jig");
        dict.insert("hub");
        dict.insert("low");
        dict.insert("did");
        dict.insert("tin");
        dict.insert("get");
        dict.insert("gte");
        dict.insert("sox");
        dict.insert("lei");
        dict.insert("mig");
        dict.insert("fig");
        dict.insert("lon");
        dict.insert("use");
        dict.insert("ban");
        dict.insert("flo");
        dict.insert("nov");
        dict.insert("jut");
        dict.insert("bag");
        dict.insert("mir");
        dict.insert("sty");
        dict.insert("lap");
        dict.insert("two");
        dict.insert("ins");
        dict.insert("con");
        dict.insert("ant");
        dict.insert("net");
        dict.insert("tux");
        dict.insert("ode");
        dict.insert("stu");
        dict.insert("mug");
        dict.insert("cad");
        dict.insert("nap");
        dict.insert("gun");
        dict.insert("fop");
        dict.insert("tot");
        dict.insert("sow");
        dict.insert("sal");
        dict.insert("sic");
        dict.insert("ted");
        dict.insert("wot");
        dict.insert("del");
        dict.insert("imp");
        dict.insert("cob");
        dict.insert("way");
        dict.insert("ann");
        dict.insert("tan");
        dict.insert("mci");
        dict.insert("job");
        dict.insert("wet");
        dict.insert("ism");
        dict.insert("err");
        dict.insert("him");
        dict.insert("all");
        dict.insert("pad");
        dict.insert("hah");
        dict.insert("hie");
        dict.insert("aim");
        dict.insert("ike");
        dict.insert("jed");
        dict.insert("ego");
        dict.insert("mac");
        dict.insert("baa");
        dict.insert("min");
        dict.insert("com");
        dict.insert("ill");
        dict.insert("was");
        dict.insert("cab");
        dict.insert("ago");
        dict.insert("ina");
        dict.insert("big");
        dict.insert("ilk");
        dict.insert("gal");
        dict.insert("tap");
        dict.insert("duh");
        dict.insert("ola");
        dict.insert("ran");
        dict.insert("lab");
        dict.insert("top");
        dict.insert("gob");
        dict.insert("hot");
        dict.insert("ora");
        dict.insert("tia");
        dict.insert("kip");
        dict.insert("han");
        dict.insert("met");
        dict.insert("hut");
        dict.insert("she");
        dict.insert("sac");
        dict.insert("fed");
        dict.insert("goo");
        dict.insert("tee");
        dict.insert("ell");
        dict.insert("not");
        dict.insert("act");
        dict.insert("gil");
        dict.insert("rut");
        dict.insert("ala");
        dict.insert("ape");
        dict.insert("rig");
        dict.insert("cid");
        dict.insert("god");
        dict.insert("duo");
        dict.insert("lin");
        dict.insert("aid");
        dict.insert("gel");
        dict.insert("awl");
        dict.insert("lag");
        dict.insert("elf");
        dict.insert("liz");
        dict.insert("ref");
        dict.insert("aha");
        dict.insert("fib");
        dict.insert("oho");
        dict.insert("tho");
        dict.insert("her");
        dict.insert("nor");
        dict.insert("ace");
        dict.insert("adz");
        dict.insert("fun");
        dict.insert("ned");
        dict.insert("coo");
        dict.insert("win");
        dict.insert("tao");
        dict.insert("coy");
        dict.insert("van");
        dict.insert("man");
        dict.insert("pit");
        dict.insert("guy");
        dict.insert("foe");
        dict.insert("hid");
        dict.insert("mai");
        dict.insert("sup");
        dict.insert("jay");
        dict.insert("hob");
        dict.insert("mow");
        dict.insert("jot");
        dict.insert("are");
        dict.insert("pol");
        dict.insert("arc");
        dict.insert("lax");
        dict.insert("aft");
        dict.insert("alb");
        dict.insert("len");
        dict.insert("air");
        dict.insert("pug");
        dict.insert("pox");
        dict.insert("vow");
        dict.insert("got");
        dict.insert("meg");
        dict.insert("zoe");
        dict.insert("amp");
        dict.insert("ale");
        dict.insert("bud");
        dict.insert("gee");
        dict.insert("pin");
        dict.insert("dun");
        dict.insert("pat");
        dict.insert("ten");
        dict.insert("mob");

        Solution s;
        print(s.findLadders("cet", "ism", dict));
    }

    return 0;
}
