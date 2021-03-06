// feng.c 静风师太
// Modified by That Oct.1997
inherit NPC;
string ask_yao();
string ask_jian();

void create()
{
        set_name("静风师太", ({ "jingfeng shitai","jingfeng","shitai"}));
        set("long",
      "她是一位中年师太，只见她眉目底垂，手中握着一把钢刀。自然而然的有股威严。\n");
        set("gender", "女性");
        set("age", 42);
        set("attitude", "peaceful");
        set("mingwang", 10000);
        set("class", "bonze");

        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("per", 30);

        set("max_kee", 1000);
        set("max_gin", 500);
        set("force", 1500);
        set("max_force", 1500);
        set("force_factor", 15);
        set("max_sen", 1500);

        set("combat_exp", 250000);
        set("score", 1000);
        set_skill("foxuexinde", 80);
        set_skill("force", 100);
        set_skill("dodge", 100);
        set_skill("parry", 90);
        set_skill("unarmed", 100);
        set_skill("sword", 100);
        set_skill("literate", 100);
        set_skill("sixiang-zhang", 100);
 
        set_skill("anying-fuxiang", 100);
        set_skill("emei-xinfa", 100);
        set_skill("huifeng-jian", 100);
        map_skill("force","emei-xinfa");
        map_skill("dodge","anying-fuxiang");
        map_skill("unarmed","sixiang-zhang");
        map_skill("sword","huifeng-jian");
        map_skill("parry","huifeng-jian");
        set("inquiry", ([
                "伤药" : (: ask_yao :),
                "武器" : (: ask_jian :),
        ]));
        set("gao_count",3);
        set("jian_count",2);
        create_family("峨嵋派", 4, "弟子");

        setup();
        carry_object("/obj/weapon/sword")->wield();
        carry_object("/obj/armor/ni-cloth.c")->wear();
        carry_object("/obj/armor/ni-xie")->wear();
}
void attempt_apprentice(object ob)
{
    command ("say 阿弥陀佛！贫尼不收弟子。\n");
    command ("say 你若想继续学峨嵋派的功夫，还是去找我俗家师妹吧。\n");
    return;
}
string ask_yao()
{
        mapping fam;
        object ob;

        if (!(fam = this_player()->query("family")) || fam["family_name"] != "峨嵋派")
                return RANK_D->query_respect(this_player()) +
                "与本派素无来往，不知此话从何谈起？";
        if (this_player()->query("eff_kee")>=this_player()->query("max_kee"))
                return "你未曾受伤，讨这药膏做什么？";
        if (ob = present("tianxiang gao", this_player()))
                return "你身上不是带着本门秘药？！";
        if (query("gao_count") < 1)
                return "你来晚了，本门秘药已尽数给了本派弟子。";
        add("gao_count", -1);
        ob = new("/d/emei/obj/tianxiang-gao");
        ob->move(this_player());
        return "我这里有本门秘药，你拿去疗伤吧。";
}

string ask_jian()
{
        mapping fam;
        object ob;

        if (!(fam = this_player()->query("family")) || fam["family_name"] != "峨嵋派")
                return RANK_D->query_respect(this_player()) +
                "与本派素无来往，不知此话从何谈起？";
        if (query("jian_count") < 1)
                return "我现在没有什么武器好给，你下次在来吧。";
        if (ob = present("ruanjian", this_player()))
                return "你身上不是带着武器吗？怎么还来要！";
        add("jian_count", -1);
        ob = new("/d/emei/obj/ruanjian");
        ob->move(this_player());
        return "我这里有一把软剑，你拿去用吧。";
}

