#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

// --- FUNKCE PRO ČTENÍ MIKROFONU ---
// Zde je potřeba implementovat Android JNI pro získání dat z mikrofonu.
// Momentálně vrací simulovanou hodnotu (0.0).
float getMicrophoneVolume() {
    // TODO: Přidat Android Oboe nebo JNI AudioRecord kód
    // Mělo by vracet hodnotu od 0.0 (ticho) do 1.0 (řev)
    return 0.0f; 
}

// --- ÚPRAVA HERNÍ TŘÍDY PLAYLAYER ---
class $modify(VoicePlayLayer, PlayLayer) {

    // Custom proměnné uvnitř naší upravené třídy
    struct Fields {
        bool isVoiceJumping = false;
    };

    // postUpdate se volá každý jeden snímek (frame) hry
    void postUpdate(float dt) {
        // Zavolá původní kód hry, aby se nic nerozbilo
        PlayLayer::postUpdate(dt);

        // Pokud hráč neexistuje (např. jsme v menu), přeruš funkci
        if (!m_player1) return;

        // Získej aktuální hlasitost
        float volume = getMicrophoneVolume();

        // Práh hlasitosti pro skok (80%)
        float threshold = 0.8f;

        // Pokud je hlasitost vyšší než práh a ještě neskáčeme -> SKOČ
        if (volume > threshold && !m_fields->isVoiceJumping) {
            m_fields->isVoiceJumping = true;
            m_player1->pushButton(static_cast<int>(PlayerButton::Jump));
        }
        // Pokud hlasitost klesne pod práh a skákali jsme -> PUSŤ TLAČÍTKO
        else if (volume <= threshold && m_fields->isVoiceJumping) {
            m_fields->isVoiceJumping = false;
            m_player1->releaseButton(static_cast<int>(PlayerButton::Jump));
        }
    }
};
