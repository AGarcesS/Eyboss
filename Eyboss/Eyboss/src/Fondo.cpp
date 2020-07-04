//#include "Fondo.h"
//#include "ETSIDI.h"
//
//void Fondo::Dibuja() {
//	glEnable(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(textura).id);
//	glDisable(GL_LIGHTING);
//	glBegin(GL_POLYGON);
//	glColor3f(1, 1, 1);
//	/*glTexCoord2d(0, 1); glVertex3f(limite1.x, limite1.y, z);
//	glTexCoord2d(1, 1); glVertex3f(limite2.x, limite1.y, z);
//	glTexCoord2d(1, 0); glVertex3f(limite2.x, limite2.y, z);
//	glTexCoord2d(0, 0); glVertex3f(limite1.x, limite2.y, z);*/
//	glTexCoord2d(0, 0); glVertex3f(limite1.x, limite2.y, z);
//	glTexCoord2d(2, 0); glVertex3f(limite2.x, limite2.y, z);
//	glTexCoord2d(2, 1); glVertex3f(limite2.x, limite1.y, z);
//	glTexCoord2d(0, 1); glVertex3f(limite1.x, limite1.y, z);
//	glEnd();
//	glEnable(GL_LIGHTING);
//	glDisable(GL_TEXTURE_2D);
//}
//
//
//
////glTexCoord2d(0, 0); glVertex2f(limite1.x, limite2.y);
////glTexCoord2d(1, 0); glVertex2f(limite2.x, limite2.y);
////glTexCoord2d(1, 1); glVertex2f(limite2.x, limite1.y);
////glTexCoord2d(0, 1); glVertex2f(limite1.x, limite1.y);