# ArDMXino
A DMX512 controller built with an Arduino Uno, a RS-485 transceiver and some soldering

built following https://github.com/GadgetReboot/Arduino/tree/adf95ad05b710d7a58421f86df913644a04948d4/Uno/DMX512

This sketch is designed to control a moving head light via DMX. 
There are three modes: 
- Dinner Mode, where the moving head rotates slowly with warm lighting;
- Party Mode, where the moving head spins quickly, changing colors rapidly;
- Joystick Mode, where you can direct the moving head with a joystick.

One button is dedicated to switching modes, while two others are used to save/reset the current joystick position and to change the light color.

Build up with:

- Arduino Uno R3 smd ([AliExpress](https://it.aliexpress.com/item/1005002992077610.html?spm=a2g0o.productlist.main.1.5eb0LPAzLPAzVN&algo_pvid=badea915-624b-4f49-b532-b0922fda2bb5&algo_exp_id=badea915-624b-4f49-b532-b0922fda2bb5-0&pdp_npi=4%40dis%21EUR%214.46%210.96%21%21%214.60%210.99%21%40210384cc17316236008657810ec7d7%2112000023107661369%21sea%21IT%210%21ABX&curPageLogUid=qCcY2iSrykOQ&utparam-url=scene%3Asearch%7Cquery_from%3A))
- RS-485 Transceiver module ([AliExpress](https://it.aliexpress.com/item/1005005737922222.html?spm=a2g0o.productlist.main.13.2ccc7ff6Kl2FWY&algo_pvid=58d645c4-8ea1-48aa-b314-8c44815514da&algo_exp_id=58d645c4-8ea1-48aa-b314-8c44815514da-6&pdp_npi=4%40dis%21EUR%211.23%210.96%21%21%211.27%210.99%21%40210386d117316237781097671e1eb5%2112000034165104857%21sea%21IT%210%21ABX&curPageLogUid=ykW5AXFz7aTd&utparam-url=scene%3Asearch%7Cquery_from%3A))
- Joystick shield ([AliExpress](https://it.aliexpress.com/item/1005006422108315.html?spm=a2g0o.productlist.main.1.6a844b06THYIvU&algo_pvid=59acbd93-c0d3-4404-a324-018fef63734e&algo_exp_id=59acbd93-c0d3-4404-a324-018fef63734e-0&pdp_npi=4%40dis%21EUR%212.63%210.96%21%21%212.71%210.99%21%40211b619a17316238343313670eb84d%2112000037107330472%21sea%21IT%210%21ABX&curPageLogUid=SWINYDtoz6TC&utparam-url=scene%3Asearch%7Cquery_from%3A))
