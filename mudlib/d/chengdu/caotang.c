//bye enter

inherit ROOM;

void create()
{
        set("short", "杜甫草堂");
	set("long", @LONG
这里就是著名的杜甫草堂了。草堂内，小桥，流水，梅
园交错庭中，另有春之梅，夏之荷，秋之菊，冬之兰可赏，置
身其中，让人有发古之幽思，又享大自然之浪漫。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
            "southwest" : __DIR__"xiaoxiang1",
            "east" : __DIR__"cdta",
            ]));

        set("no_clean_up", 0);
        set("no_fight", 1);
        set("objects",([
            __DIR__"npc/dufu" : 1,
            __DIR__"npc/xuetong" : 2,
        ]));

	setup();
	replace_program(ROOM);
}
