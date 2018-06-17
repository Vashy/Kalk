#include "KeypadInput.h"
#include <cfloat>
#include <QKeyEvent>

KeypadInput::KeypadInput(QWidget* parent, const QString& text, QDoubleValidator* validator)
    : QLineEdit(text, parent),
      inputValidator(validator)
{
    if (validator == nullptr)
        inputValidator = new QDoubleValidator(DBL_MIN, DBL_MAX, 50, this);
    setValidator(inputValidator);
    //setFocus();
}

//impedisce l'inserimento di due punti di virgola
void KeypadInput::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_Period: //key '.' premuta
            if (!text().contains('.')) //la stringa non contiene già il punto?
                QLineEdit::keyPressEvent(event);
            break;
        case Qt::Key_Comma: //impedisce l'inserimento della virgola
            break;
        default:
            QLineEdit::keyPressEvent(event); //si comporta come la superclasse
            break;
    }
}
