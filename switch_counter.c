


#define SWITCH_PRESSED(r)           !input(r)
#define TURN_ON(r)                  output_high(r)
#define TURN_OFF(r)                 output_low(r)
#define delay(r)                    delay_ms(r)

unsigned char selectionCounter = 0b00000000;

void mediaPlayer();

int main( ) {
    
    fprintf("PLAYER HAS BOOTED SUCCESSFULLY\n\r");
    
    while( TRUE )
    {
        mediaPlayer();
    }
    return 0;
}

void mediaPlayer()
{  
    if( SWITCH_PRESSED( GAMES )) {
        delay(100);
        
        selectionCounter = (selectionCounter & 0x10) ? ++selectionCounter : 0x11;
        selectContent(selectionCounter);
        
    }
    else if(SWITCH_PRESSED( MOVIES ))
    {
        delay(100);
         
        selectionCounter = (selectionCounter & 0x20) ? ++selectionCounter : 0x21;
        selectContent(selectionCounter);
    }
    else if( SWITCH_PRESSED( MUSIC ))
    {
        delay(100);
        
        selectionCounter = (selectionCounter & 0x40) ? ++selectionCounter : 0x41;
        selectContent(selectionCounter);
    }    
}


void selectContent(unsigned char selector)
{
    switch(selector)
    {
        
        ////////////////////////////////////////
        case 0x11: 
            break;
        case 0x12: 
            break;
        case 0x13:  
            break;
        case 0x14: 
            break;
        case 0x15:  selectionCounter = 0x00;
            break;
                    
        /////////////////////////////////////////
        case 0x21: 
            break;
        case 0x22: 
            break;
        case 0x23: 
            break;
        case 0x24:  
            break;
        case 0x25:  selectionCounter = 0x00;
            break;
 
            
        //////////////////////////////////////////
        case 0x41:  
            break;
        case 0x42:  
            break;
        case 0x43: 
            break;
        case 0x44:  
            break;
        case 0x45:  selectionCounter = 0x00;
            break;
    }
}
