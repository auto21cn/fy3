// 

inherit ITEM;

void create()
{
        set_name("《阿弥陀经》", ({"amituojing", "jing" }));
        set_weight(100);
        set("unit", "本");
        set("long",
                "小乘佛学经典，一定要读一读.\n"
             );
        set("value", 1000);
        set("skill", ([
                "name": "foxuexinde",
                "max_skill":    20 
        ]) );
}
 
