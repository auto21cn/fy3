// 

inherit ITEM;

void create()
{
	set_name("《内功心法下卷》",({"neigongxia","xia"}));
        set_weight(100);
        set("unit", "本");
        set("long",
	"一本记载着呼吸吐纳运气法门的武学书籍。\n"
             );
	set("value",3000);
        set("skill", ([
	"name":"force",
        "exp_required":10000,
        "max_skill":60,
        "sen_cost":30,
        ]) );
}
 
