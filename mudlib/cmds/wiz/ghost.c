#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        if (!arg || arg!="-p") {
                me->set_ghost(1);
                write("你变成了鬼！\n");
        }
        else {
                me->set_ghost(0);
                write("你又投胎做人了！\n");
        }
        return 1;
}
