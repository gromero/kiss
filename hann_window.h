#ifndef _HANN_WINDOW_H
#define _HANN_WINDOW_H

#define W_TS_SIZE 480

static const float hann_window[W_TS_SIZE] = {
    0.0000000000000000000000000, 0.0000428259372711181640625, 0.0001713335514068603515625, 0.0003854930400848388671875,
    0.0006852447986602783203125, 0.0010705292224884033203125, 0.0015413463115692138671875, 0.0020975470542907714843750,
    0.0027390420436859130859375, 0.0034657716751098632812500, 0.0042775571346282958984375, 0.0051743090152740478515625,
    0.0061558187007904052734375, 0.0072219669818878173828125, 0.0083725452423095703125000, 0.0096073746681213378906250,
    0.0109261870384216308593750, 0.0123288333415985107421875, 0.0138150453567504882812500, 0.0153845548629760742187500,
    0.0170370936393737792968750, 0.0187723934650421142578125, 0.0205901265144348144531250, 0.0224900245666503906250000,
    0.0244717299938201904296875, 0.0265349447727203369140625, 0.0286792516708374023437500, 0.0309043228626251220703125,
    0.0332098007202148437500000, 0.0355952382087707519531250, 0.0380602478981018066406250, 0.0406043827533721923828125,
    0.0432272851467132568359375, 0.0459284186363220214843750, 0.0487073659896850585937500, 0.0515636503696441650390625,
    0.0544967353343963623046875, 0.0575061738491058349609375, 0.0605914592742919921875000, 0.0637519955635070800781250,
    0.0669873058795928955078125, 0.0702967941761016845703125, 0.0736799240112304687500000, 0.0771360993385314941406250,
    0.0806647241115570068359375, 0.0842652022838592529296875, 0.0879369080066680908203125, 0.0916792154312133789062500,
    0.0954915285110473632812500, 0.0993731021881103515625000, 0.1033233404159545898437500, 0.1073415279388427734375000,
    0.1114270091056823730468750, 0.1155790984630584716796875, 0.1197970509529113769531250, 0.1240801215171813964843750,
    0.1284275949001312255859375, 0.1328387558460235595703125, 0.1373128294944763183593750, 0.1418490409851074218750000,
    0.1464466452598571777343750, 0.1511048078536987304687500, 0.1558227241039276123046875, 0.1605996489524841308593750,
    0.1654347181320190429687500, 0.1703270971775054931640625, 0.1752760112285614013671875, 0.1802805066108703613281250,
    0.1853398084640502929687500, 0.1904530227184295654296875, 0.1956193149089813232421875, 0.2008377313613891601562500,
    0.2061073780059814453125000, 0.2114274203777313232421875, 0.2167968750000000000000000, 0.2222149074077606201171875,
    0.2276805043220520019531250, 0.2331927418708801269531250, 0.2387507557868957519531250, 0.2443534433841705322265625,
    0.2500000000000000000000000, 0.2556894421577453613281250, 0.2614206075668334960937500, 0.2671927511692047119140625,
    0.2730047702789306640625000, 0.2788556516170501708984375, 0.2847444713115692138671875, 0.2906701564788818359375000,
    0.2966316938400268554687500, 0.3026280403137207031250000, 0.3086582720279693603515625, 0.3147212862968444824218750,
    0.3208160102367401123046875, 0.3269414901733398437500000, 0.3330965936183929443359375, 0.3392803072929382324218750,
    0.3454915285110473632812500, 0.3517292439937591552734375, 0.3579923808574676513671875, 0.3642797470092773437500000,
    0.3705904483795166015625000, 0.3769233822822570800781250, 0.3832773566246032714843750, 0.3896512687206268310546875,
    0.3960441648960113525390625, 0.4024548828601837158203125, 0.4088822603225708007812500, 0.4153252840042114257812500,
    0.4217828214168548583984375, 0.4282537102699279785156250, 0.4347369372844696044921875, 0.4412313103675842285156250,
    0.4477357864379882812500000, 0.4542491734027862548828125, 0.4607704579830169677734375, 0.4672984480857849121093750,
    0.4738320112228393554687500, 0.4803701043128967285156250, 0.4869115650653839111328125, 0.4934552609920501708984375,
    0.5000000000000000000000000, 0.5065448284149169921875000, 0.5130885243415832519531250, 0.5196298956871032714843750,
    0.5261679887771606445312500, 0.5327016115188598632812500, 0.5392295718193054199218750, 0.5457507967948913574218750,
    0.5522642731666564941406250, 0.5587687492370605468750000, 0.5652630925178527832031250, 0.5717463493347167968750000,
    0.5782172679901123046875000, 0.5846748352050781250000000, 0.5911177396774291992187500, 0.5975451469421386718750000,
    0.6039558649063110351562500, 0.6103487014770507812500000, 0.6167227029800415039062500, 0.6230766773223876953125000,
    0.6294095516204833984375000, 0.6357202529907226562500000, 0.6420077085494995117187500, 0.6482708454132080078125000,
    0.6545085310935974121093750, 0.6607197523117065429687500, 0.6669034361839294433593750, 0.6730585694313049316406250,
    0.6791839599609375000000000, 0.6852787137031555175781250, 0.6913417577743530273437500, 0.6973719596862792968750000,
    0.7033683061599731445312500, 0.7093299031257629394531250, 0.7152555584907531738281250, 0.7211443185806274414062500,
    0.7269952893257141113281250, 0.7328072786331176757812500, 0.7385793924331665039062500, 0.7443106770515441894531250,
    0.7500000000000000000000000, 0.7556465864181518554687500, 0.7612493634223937988281250, 0.7668071985244750976562500,
    0.7723195552825927734375000, 0.7777850627899169921875000, 0.7832031250000000000000000, 0.7885726094245910644531250,
    0.7938927412033081054687500, 0.7991623878479003906250000, 0.8043807744979858398437500, 0.8095469474792480468750000,
    0.8146602511405944824218750, 0.8197195529937744140625000, 0.8247240781784057617187500, 0.8296729326248168945312500,
    0.8345653414726257324218750, 0.8394004106521606445312500, 0.8441772460937500000000000, 0.8488952517509460449218750,
    0.8535533547401428222656250, 0.8581510186195373535156250, 0.8626872301101684570312500, 0.8671613335609436035156250,
    0.8715723752975463867187500, 0.8759199380874633789062500, 0.8802030086517333984375000, 0.8844208717346191406250000,
    0.8885730504989624023437500, 0.8926584720611572265625000, 0.8966767191886901855468750, 0.9006268978118896484375000,
    0.9045084714889526367187500, 0.9083207845687866210937500, 0.9120631217956542968750000, 0.9157348275184631347656250,
    0.9193353652954101562500000, 0.9228639602661132812500000, 0.9263200759887695312500000, 0.9297032356262207031250000,
    0.9330126643180847167968750, 0.9362480044364929199218750, 0.9394085407257080078125000, 0.9424938559532165527343750,
    0.9455032944679260253906250, 0.9484363794326782226562500, 0.9512926340103149414062500, 0.9540716409683227539062500,
    0.9567727446556091308593750, 0.9593956470489501953125000, 0.9619398117065429687500000, 0.9644048213958740234375000,
    0.9667901992797851562500000, 0.9690956473350524902343750, 0.9713207483291625976562500, 0.9734650850296020507812500,
    0.9755282998085021972656250, 0.9775099754333496093750000, 0.9794098734855651855468750, 0.9812276363372802734375000,
    0.9829629659652709960937500, 0.9846154451370239257812500, 0.9861849546432495117187500, 0.9876711368560791015625000,
    0.9890738129615783691406250, 0.9903926849365234375000000, 0.9916274547576904296875000, 0.9927780628204345703125000,
    0.9938441514968872070312500, 0.9948257207870483398437500, 0.9957224130630493164062500, 0.9965342283248901367187500,
    0.9972609281539916992187500, 0.9979024529457092285156250, 0.9984586834907531738281250, 0.9989295005798339843750000,
    0.9993147850036621093750000, 0.9996144771575927734375000, 0.9998286962509155273437500, 0.9999572038650512695312500,
    1.0000000000000000000000000, 0.9999572038650512695312500, 0.9998286962509155273437500, 0.9996144771575927734375000,
    0.9993147850036621093750000, 0.9989294409751892089843750, 0.9984586834907531738281250, 0.9979024529457092285156250,
    0.9972609281539916992187500, 0.9965342283248901367187500, 0.9957224130630493164062500, 0.9948257207870483398437500,
    0.9938441514968872070312500, 0.9927780628204345703125000, 0.9916274547576904296875000, 0.9903926253318786621093750,
    0.9890737533569335937500000, 0.9876711368560791015625000, 0.9861849546432495117187500, 0.9846154451370239257812500,
    0.9829629063606262207031250, 0.9812276363372802734375000, 0.9794098138809204101562500, 0.9775099754333496093750000,
    0.9755282402038574218750000, 0.9734650254249572753906250, 0.9713206887245178222656250, 0.9690957069396972656250000,
    0.9667901992797851562500000, 0.9644047617912292480468750, 0.9619397521018981933593750, 0.9593955278396606445312500,
    0.9567726850509643554687500, 0.9540715217590332031250000, 0.9512926340103149414062500, 0.9484363794326782226562500,
    0.9455032348632812500000000, 0.9424937963485717773437500, 0.9394085407257080078125000, 0.9362479448318481445312500,
    0.9330126643180847167968750, 0.9297032356262207031250000, 0.9263200759887695312500000, 0.9228639006614685058593750,
    0.9193352460861206054687500, 0.9157347679138183593750000, 0.9120630025863647460937500, 0.9083207249641418457031250,
    0.9045084714889526367187500, 0.9006268978118896484375000, 0.8966765999794006347656250, 0.8926584720611572265625000,
    0.8885729908943176269531250, 0.8844208717346191406250000, 0.8802029490470886230468750, 0.8759198784828186035156250,
    0.8715724349021911621093750, 0.8671612143516540527343750, 0.8626871705055236816406250, 0.8581508994102478027343750,
    0.8535533547401428222656250, 0.8488951921463012695312500, 0.8441772460937500000000000, 0.8394004106521606445312500,
    0.8345652818679809570312500, 0.8296729326248168945312500, 0.8247239589691162109375000, 0.8197193741798400878906250,
    0.8146601915359497070312500, 0.8095468878746032714843750, 0.8043807744979858398437500, 0.7991622686386108398437500,
    0.7938925027847290039062500, 0.7885724306106567382812500, 0.7832031250000000000000000, 0.7777851819992065429687500,
    0.7723195552825927734375000, 0.7668071985244750976562500, 0.7612491846084594726562500, 0.7556465864181518554687500,
    0.7499999403953552246093750, 0.7443104982376098632812500, 0.7385793924331665039062500, 0.7328072190284729003906250,
    0.7269951105117797851562500, 0.7211443185806274414062500, 0.7152557373046875000000000, 0.7093299627304077148437500,
    0.7033683061599731445312500, 0.6973718404769897460937500, 0.6913417577743530273437500, 0.6852787137031555175781250,
    0.6791839003562927246093750, 0.6730583906173706054687500, 0.6669034361839294433593750, 0.6607196331024169921875000,
    0.6545083522796630859375000, 0.6482705473899841308593750, 0.6420075893402099609375000, 0.6357200145721435546875000,
    0.6294094920158386230468750, 0.6230767965316772460937500, 0.6167227029800415039062500, 0.6103487014770507812500000,
    0.6039557456970214843750000, 0.5975452065467834472656250, 0.5911177396774291992187500, 0.5846745967864990234375000,
    0.5782170295715332031250000, 0.5717462301254272460937500, 0.5652629733085632324218750, 0.5587684512138366699218750,
    0.5522641539573669433593750, 0.5457509160041809082031250, 0.5392295718193054199218750, 0.5327014923095703125000000,
    0.5261680483818054199218750, 0.5196298956871032714843750, 0.5130884051322937011718750, 0.5065446496009826660156250,
    0.5000000000000000000000000, 0.4934551119804382324218750, 0.4869113564491271972656250, 0.4803700745105743408203125,
    0.4738319218158721923828125, 0.4672982692718505859375000, 0.4607701897621154785156250, 0.4542493224143981933593750,
    0.4477358162403106689453125, 0.4412312805652618408203125, 0.4347367882728576660156250, 0.4282537400722503662109375,
    0.4217827320098876953125000, 0.4153251349925994873046875, 0.4088822603225708007812500, 0.4024547934532165527343750,
    0.3960440158843994140625000, 0.3896510601043701171875000, 0.3832772672176361083984375, 0.3769232034683227539062500,
    0.3705902695655822753906250, 0.3642797172069549560546875, 0.3579924106597900390625000, 0.3517292141914367675781250,
    0.3454914391040802001953125, 0.3392803668975830078125000, 0.3330965638160705566406250, 0.3269414007663726806640625,
    0.3208158612251281738281250, 0.3147212862968444824218750, 0.3086582124233245849609375, 0.3026279211044311523437500,
    0.2966314554214477539062500, 0.2906700372695922851562500, 0.2847442924976348876953125, 0.2788556516170501708984375,
    0.2730048894882202148437500, 0.2671927809715270996093750, 0.2614206075668334960937500, 0.2556892931461334228515625,
    0.2500000596046447753906250, 0.2443534433841705322265625, 0.2387506365776062011718750, 0.2331925928592681884765625,
    0.2276804447174072265625000, 0.2222147881984710693359375, 0.2167967259883880615234375, 0.2114271819591522216796875,
    0.2061072587966918945312500, 0.2008377313613891601562500, 0.1956192255020141601562500, 0.1904531121253967285156250,
    0.1853398084640502929687500, 0.1802804470062255859375000, 0.1752758622169494628906250, 0.1703270971775054931640625,
    0.1654346585273742675781250, 0.1605995297431945800781250, 0.1558225452899932861328125, 0.1511047184467315673828125,
    0.1464464664459228515625000, 0.1418488621711730957031250, 0.1373127400875091552734375, 0.1328387856483459472656250,
    0.1284275650978088378906250, 0.1240800321102142333984375, 0.1197970509529113769531250, 0.1155790686607360839843750,
    0.1114269495010375976562500, 0.1073414087295532226562500, 0.1033233106136322021484375, 0.0993730127811431884765625,
    0.0954913794994354248046875, 0.0916791856288909912109375, 0.0879368185997009277343750, 0.0842650830745697021484375,
    0.0806646943092346191406250, 0.0771361589431762695312500, 0.0736799240112304687500000, 0.0702967643737792968750000,
    0.0669872164726257324218750, 0.0637519955635070800781250, 0.0605913996696472167968750, 0.0575061142444610595703125,
    0.0544967353343963623046875, 0.0515635907649993896484375, 0.0487073063850402832031250, 0.0459282994270324707031250,
    0.0432272255420684814453125, 0.0406043231487274169921875, 0.0380602180957794189453125, 0.0355951786041259765625000,
    0.0332098007202148437500000, 0.0309043228626251220703125, 0.0286792218685150146484375, 0.0265349447727203369140625,
    0.0244717299938201904296875, 0.0224899947643280029296875, 0.0205900669097900390625000, 0.0187723636627197265625000,
    0.0170370638370513916015625, 0.0153844952583312988281250, 0.0138149857521057128906250, 0.0123288035392761230468750,
    0.0109262168407440185546875, 0.0096073448657989501953125, 0.0083725750446319580078125, 0.0072219669818878173828125,
    0.0061558187007904052734375, 0.0051742792129516601562500, 0.0042775571346282958984375, 0.0034657716751098632812500,
    0.0027390420436859130859375, 0.0020975172519683837890625, 0.0015413165092468261718750, 0.0010705292224884033203125,
    0.0006852149963378906250000, 0.0003854632377624511718750, 0.0001713335514068603515625, 0.0000428259372711181640625,
};

void apply_hann_window(float*);

#endif // _HANN_WINDOW_H
