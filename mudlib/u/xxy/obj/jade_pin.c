#include <ansi.h>
inherit ITEM;
inherit __DIR__"vacuous.c";

void create()
{      object ob;
        set_name("白玉小瓶", ({ "pin", "bottle", "xiaopin"}) );
        set_weight(500);
        set_max_encumbrance(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "一个温玉所制的瓶子,上面的盖子是用"+RED+"红玛瑙"+NOR+"作成的。\n");
                set("value",1000);
        }
                ob=new("/u/aug/jiuhua.c");
                             ob->move(this_object());
        set("vacuous",([
                      "status":1,
                      "name":RED"玛瑙瓶塞"NOR,
            ]));
}
int is_container() { return 1; }
