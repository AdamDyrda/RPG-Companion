/**
*@file Player.cpp
*@brief implementation of the Player class.
**/


#include "../inc/Player.h"
#include <string>
#include <wx/wx.h>


std::string Player::GetName() {
    return name;
}

std::string Player::GetOccupation() const {
    return occupation;
}

std::string Player::GetBirthplace() const {
    return birthplace;
}

std::string Player::GetResistance() const {
    return residence;
}

std::string Player::GetPronoun() const {
    return pronoun;
}
int Player::GetAge() const {
    return age;
}
int Player::GetStrength() const {
    return stats.strength;
}
int Player::GetConcentration() const {
    return stats.concentration;
}
int Player::GetDexterity() const {
    return stats.dexterity;
}
int Player::GetIntelligence() const {
    return stats.intelligence;
}
int Player::GetSize() const {
    return stats.size;
}
int Player::GetPower() const {
    return stats.power;
}
int Player::GetAppearance() const {
    return stats.appearance;
}
int Player::GetEducation() const {
    return stats.education;
}
int Player::GetHitPoints() const {
    return stats.HitPoints;
}
int Player::GetMagicPoints() const {
    return stats.MagicPoints;
}
int Player::GetLuckPoints() const {
    return stats.LuckPoints;
}
int Player::GetLuck() const {
    return stats.Luck;
}
int Player::GetSanity() const {
    return stats.Sanity;
}
int Player::GetAccounting() const {
    return skills.accounting;
}
int Player::GetAnthropology() const {
    return skills.anthropology;
}
int Player::GetApprise() const {
    return skills.appraise;
}
int Player::GetArchaeology() const {
    return skills.archaeology;
}
int Player::GetArt() const {
    return skills.art;
}
int Player::GetCharm() const {
    return skills.charm;
}
int Player::GetClimb() const {
    return skills.climb;
}
int Player::GetCreditRating() const {
    return skills.creditRating;
}
int Player::GetCtulhuMythos() const {
    return skills.cthulhuMythos;
}
int Player::GetDisguise() const {
    return skills.disguise;
}
int Player::GetDodge() const {
    return skills.dodge;
}
int Player::GetDriveAuto() const {
    return skills.driveAuto;
}
int Player::GetElectricalRepair() const {
    return skills.electricalRepair;
}
int Player::GetFastTalk() const {
    return skills.fastTalk;
}
int Player::GetFighting() const {
    return skills.fighting;
}
int Player::GetFirearmsHandgun() const {
    return skills.firearmsHandgun;
}
int Player::GetFirearmsRifle() const {
    return skills.firearmsRifle;
}
int Player::GetFirstAid() const {
    return skills.firstAid;
}
int Player::GetHistory() const {
    return skills.history;
}
int Player::GetIntimidate() const {
    return skills.intimidate;
}
int Player::GetJump() const {
    return skills.jump;
}
int Player::GetLanguageOther() const {
    return skills.languageOther;
}
int Player::GetLanguageOwn() const {
    return skills.languageOwn;
}
int Player::GetLaw() const {
    return skills.law;
}
int Player::GetLibraryUse() const {
    return skills.libraryUse;
}
int Player::GetListen() const {
    return skills.listen;
}
int Player::GetLocksmith() const {
    return skills.locksmith;
}
int Player::GetMechanicalRepair() const {
    return skills.mechanicalRepair;
}
int Player::GetMedicine() const {
    return skills.medicine;
}
int Player::GetNaturalWorld() const {
    return skills.naturalWorld;
}
int Player::GetOccult() const {
    return skills.occult;
}
int Player::GetPersuade() const {
    return skills.persuade;
}
int Player::GetPilot() const {
    return skills.pilot;
}
int Player::GetPsychoanalysis() const {
    return skills.psychoanalysis;
}
int Player::GetPsychology() const {
    return skills.psychology;
}
int Player::GetRide() const {
    return skills.ride;
}
int Player::GetScience() const {
    return skills.science;
}
int Player::GetSleightOfHand() const {
    return skills.sleightOfHand;
}
int Player::GetSpotHidden() const {
    return skills.spotHidden;
}
int Player::GetStealth() const {
    return skills.stealth;
}
int Player::GetSurvival() const {
    return skills.survival;
}
int Player::GetSwim() const {
    return skills.swim;
}
int Player::GetThrowing() const {
    return skills.throwing;
}
int Player::GetTrack() const {
    return skills.track;
}

int Player::GetNavigate() const {
    return skills.navigate;
}

void Player::SetName(const wxString& name) {
    this->name = name.ToStdString();
}
void Player::SetOccupation(const wxString& occupation) {
    this->occupation = occupation.ToStdString();
}
void Player::SetBirthplace(const wxString& birthplace) {
    this->birthplace = birthplace.ToStdString();
}
void Player::SetResidence(const wxString& residence) {
    this->residence = residence.ToStdString();
}
void Player::SetPronoun(const wxString& pronoun) {
    this->pronoun = pronoun.ToStdString();
}
void Player::SetAge(const wxString& age) {
    if (age.IsNumber()) {
        if (std::stoi(age.ToStdString())>0) {
            this->age = std::stoi(age.ToStdString());
            return;
        }
    }
        wxLogError("Age must be a positive number.");

}
void Player::SetStrength(const wxString& strength) {
    if (strength.IsNumber()) {
        this->stats.strength = std::stoi(strength.ToStdString());
    }
    else {
        wxLogError("Strength must be a number.");
    }
}
void Player::SetConcentration(const wxString& concentration) {
    if (concentration.IsNumber()) {
        stats.concentration = std::stoi(concentration.ToStdString());
    }
    else {
        wxLogError("Concentration must be a number.");
    }
}
void Player::SetDexterity(const wxString& dexterity) {
    if (dexterity.IsNumber()) {
        stats.dexterity = std::stoi(dexterity.ToStdString());
    }
    else {
        wxLogError("Dexterity must be a number.");
    }
}
void Player::SetIntelligence(const wxString& intelligence) {
    if (intelligence.IsNumber()) {
        stats.intelligence = std::stoi(intelligence.ToStdString());
    }
    else {
        wxLogError("Intelligence must be a number.");
    }
}
void Player::SetSize(const wxString& size) {
    if (size.IsNumber()) {
        stats.size = std::stoi(size.ToStdString());
    }
    else {
        wxLogError("Size must be a number.");
    }
}
void Player::SetPower(const wxString& power) {
    if (power.IsNumber()) {
        stats.power = std::stoi(power.ToStdString());
    }
    else {
        wxLogError("Power must be a number.");
    }
}
void Player::SetAppearance(const wxString& appearance) {
    if (appearance.IsNumber()) {
        stats.appearance = std::stoi(appearance.ToStdString());
    }
    else {
        wxLogError("Appearance must be a number.");
    }
}
void Player::SetEducation(const wxString& education) {
    if (education.IsNumber()) {
        stats.education = std::stoi(education.ToStdString());
    }
    else {
        wxLogError("Education must be a number.");
    }
}
void Player::SetHitPoints(const wxString& hitPoints) {
    if (hitPoints.IsNumber()) {
        stats.HitPoints = std::stoi(hitPoints.ToStdString());
    }
    else {
        wxLogError("Hit Points must be a number.");
    }
}
void Player::SetMagicPoints(const wxString& magicPoints) {
    if (magicPoints.IsNumber()) {
        stats.MagicPoints = std::stoi(magicPoints.ToStdString());
    }
    else {
        wxLogError("Magic Points must be a number.");
    }
}
void Player::SetLuckPoints(const wxString& luckPoints) {
    if (luckPoints.IsNumber()) {
        stats.LuckPoints = std::stoi(luckPoints.ToStdString());
    }
    else {
        wxLogError("Luck Points must be a number.");
    }
}
void Player::SetLuck(const wxString& luck) {
    if (luck.IsNumber()) {
        stats.Luck = std::stoi(luck.ToStdString());
    }
    else {
        wxLogError("Luck must be a number.");
    }
}
void Player::SetSanity(const wxString& sanity) {
    if (sanity.IsNumber()) {
        stats.Sanity = std::stoi(sanity.ToStdString());
    }
    else {
        wxLogError("Sanity must be a number.");
    }
}
void Player::SetAccounting(const wxString& accounting) {
    if (accounting.IsNumber()) {
        skills.accounting = std::stoi(accounting.ToStdString());
    }
    else {
        wxLogError("Accounting must be a number.");
    }
}
void Player::SetAnthropology(const wxString& anthropology) {
    if (anthropology.IsNumber()) {
        skills.anthropology = std::stoi(anthropology.ToStdString());
    }
    else {
        wxLogError("Anthropology must be a number.");
    }
}
void Player::SetApprise(const wxString& apprise) {
    if (apprise.IsNumber()) {
        skills.appraise = std::stoi(apprise.ToStdString());
    }
    else {
        wxLogError("Apprise must be a number.");
    }
}
void Player::SetArcheology(const wxString& archaeology) {
    if (archaeology.IsNumber()) {
        skills.archaeology = std::stoi(archaeology.ToStdString());
    }
    else {
        wxLogError("Archaeology must be a number.");
    }
}
void Player::SetArt(const wxString& art) {
    if (art.IsNumber()) {
        skills.art = std::stoi(art.ToStdString());
    }
    else {
        wxLogError("Art must be a number.");
    }
}
void Player::SetClimb(const wxString& climb) {
    if (climb.IsNumber()) {
        skills.climb = std::stoi(climb.ToStdString());
    }
    else {
        wxLogError("Charm must be a number.");
    }
}
void Player::SetCreditRating(const wxString& creditRating) {
    if (creditRating.IsNumber()) {
        skills.creditRating = std::stoi(creditRating.ToStdString());
    }
    else {
        wxLogError("Credit Rating must be a number.");
    }
}
void Player::SetCThulhuMythos(const wxString& cthulhuMythos) {
    if (cthulhuMythos.IsNumber()) {
        skills.cthulhuMythos = std::stoi(cthulhuMythos.ToStdString());
    }
    else {
        wxLogError("Cthulhu Mythos must be a number.");
    }
}
void Player::SetDisguise(const wxString& disguise) {
    if (disguise.IsNumber()) {
        skills.disguise = std::stoi(disguise.ToStdString());
    }
    else {
        wxLogError("Disguise must be a number.");
    }
}
void Player::SetDodge(const wxString& dodge) {
    if (dodge.IsNumber()) {
        skills.dodge = std::stoi(dodge.ToStdString());
    }
    else {
        wxLogError("Dodge must be a number.");
    }
}
void Player::SetDriveAuto(const wxString& driveAuto) {
    if (driveAuto.IsNumber()) {
        skills.driveAuto = std::stoi(driveAuto.ToStdString());
    }
    else {
        wxLogError("Drive Auto must be a number.");
    }
}
void Player::SetElectricalRepair(const wxString& electricalRepair) {
    if (electricalRepair.IsNumber()) {
        skills.electricalRepair = std::stoi(electricalRepair.ToStdString());
    }
    else {
        wxLogError("Electrical Repair must be a number.");
    }
}
void Player::SetFastTalk(const wxString& fastTalk) {
    if (fastTalk.IsNumber()) {
        skills.fastTalk = std::stoi(fastTalk.ToStdString());
    }
    else {
        wxLogError("Fast Talk must be a number.");
    }
}
void Player::SetFighting(const wxString& fighting) {
    if (fighting.IsNumber()) {
        skills.fighting = std::stoi(fighting.ToStdString());
    }
    else {
        wxLogError("Fighting must be a number.");
    }
}
void Player::SetFirearmsHandgun(const wxString& firearmsHandgun) {
    if (firearmsHandgun.IsNumber()) {
        skills.firearmsHandgun = std::stoi(firearmsHandgun.ToStdString());
    }
    else {
        wxLogError("Firearms Handgun must be a number.");
    }
}
void Player::SetFirearmsRifle(const wxString& firearmsRifle) {
    if (firearmsRifle.IsNumber()) {
        skills.firearmsRifle = std::stoi(firearmsRifle.ToStdString());
    }
    else {
        wxLogError("Firearms Rifle must be a number.");
    }
}
void Player::SetFirstAid(const wxString& firstAid) {
    if (firstAid.IsNumber()) {
        skills.firstAid = std::stoi(firstAid.ToStdString());
    }
    else {
        wxLogError("First Aid must be a number.");
    }
}
void Player::SetHistory(const wxString& history) {
    if (history.IsNumber()) {
        skills.history = std::stoi(history.ToStdString());
    }
    else {
        wxLogError("History must be a number.");
    }
}
void Player::SetIntimidate(const wxString& intimidate) {
    if (intimidate.IsNumber()) {
        skills.intimidate = std::stoi(intimidate.ToStdString());
    }
    else {
        wxLogError("Intimidate must be a number.");
    }
}
void Player::SetJump(const wxString& jump) {
    if (jump.IsNumber()) {
        skills.jump = std::stoi(jump.ToStdString());
    }
    else {
        wxLogError("Jump must be a number.");
    }
}
void Player::SetLanguageOther(const wxString& languageOther) {
    if (languageOther.IsNumber()) {
        skills.languageOther = std::stoi(languageOther.ToStdString());
    }
    else {
        wxLogError("Language Other must be a number.");
    }
}
void Player::SetLanguageOwn(const wxString& languageOwn) {
    if (languageOwn.IsNumber()) {
        skills.languageOwn = std::stoi(languageOwn.ToStdString());
    }
    else {
        wxLogError("Language Own must be a number.");
    }
}
void Player::SetLaw(const wxString& law) {
    if (law.IsNumber()) {
        skills.law = std::stoi(law.ToStdString());
    }
    else {
        wxLogError("Law must be a number.");
    }
}
void Player::SetLibraryUse(const wxString& libraryUse) {
    if (libraryUse.IsNumber()) {
        skills.libraryUse = std::stoi(libraryUse.ToStdString());
    }
    else {
        wxLogError("Library Use must be a number.");
    }
}
void Player::SetListen(const wxString& listen) {
    if (listen.IsNumber()) {
        skills.listen = std::stoi(listen.ToStdString());
    }
    else {
        wxLogError("Listen must be a number.");
    }
}
void Player::SetLocksmith(const wxString& locksmith) {
    if (locksmith.IsNumber()) {
        skills.locksmith = std::stoi(locksmith.ToStdString());
    }
    else {
        wxLogError("Locksmith must be a number.");
    }
}
void Player::SetMechanicalRepair(const wxString& mechanicalRepair) {
    if (mechanicalRepair.IsNumber()) {
        skills.mechanicalRepair = std::stoi(mechanicalRepair.ToStdString());
    }
    else {
        wxLogError("Mechanical Repair must be a number.");
    }
}
void Player::SetMedicine(const wxString& medicine) {
    if (medicine.IsNumber()) {
        skills.medicine = std::stoi(medicine.ToStdString());
    }
    else {
        wxLogError("Medicine must be a number.");
    }
}
void Player::SetNaturalWorld(const wxString& naturalWorld) {
    if (naturalWorld.IsNumber()) {
        skills.naturalWorld = std::stoi(naturalWorld.ToStdString());
    }
    else {
        wxLogError("Natural World must be a number.");
    }
}
void Player::SetOccult(const wxString& occult) {
    if (occult.IsNumber()) {
        skills.occult = std::stoi(occult.ToStdString());
    }
    else {
        wxLogError("Occult must be a number.");
    }
}
void Player::SetPersuade(const wxString& persuade) {
    if (persuade.IsNumber()) {
        skills.persuade = std::stoi(persuade.ToStdString());
    }
    else {
        wxLogError("Persuade must be a number.");
    }
}
void Player::SetPilot(const wxString& pilot) {
    if (pilot.IsNumber()) {
        skills.pilot = std::stoi(pilot.ToStdString());
    }
    else {
        wxLogError("Pilot must be a number.");
    }
}
void Player::SetPsychoanalysis(const wxString& psychoanalysis) {
    if (psychoanalysis.IsNumber()) {
        skills.psychoanalysis = std::stoi(psychoanalysis.ToStdString());
    }
    else {
        wxLogError("Psychoanalysis must be a number.");
    }
}
void Player::SetPsychology(const wxString& psychology) {
    if (psychology.IsNumber()) {
        skills.psychology = std::stoi(psychology.ToStdString());
    }
    else {
        wxLogError("Psychology must be a number.");
    }
}
void Player::SetRide(const wxString& ride) {
    if (ride.IsNumber()) {
        skills.ride = std::stoi(ride.ToStdString());
    }
    else {
        wxLogError("Ride must be a number.");
    }
}
void Player::SetScience(const wxString& science) {
    if (science.IsNumber()) {
        skills.science = std::stoi(science.ToStdString());
    }
    else {
        wxLogError("Science must be a number.");
    }
}
void Player::SetSleightOfHand(const wxString& sleightOfHand) {
    if (sleightOfHand.IsNumber()) {
        skills.sleightOfHand = std::stoi(sleightOfHand.ToStdString());
    }
    else {
        wxLogError("Sleight of Hand must be a number.");
    }
}
void Player::SetSpotHidden(const wxString& spotHidden) {
    if (spotHidden.IsNumber()) {
        skills.spotHidden = std::stoi(spotHidden.ToStdString());
    }
    else {
        wxLogError("Spot Hidden must be a number.");
    }
}
void Player::SetStealth(const wxString& stealth) {
    if (stealth.IsNumber()) {
        skills.stealth = std::stoi(stealth.ToStdString());
    }
    else {
        wxLogError("Stealth must be a number.");
    }
}
void Player::SetSurvival(const wxString& survival) {
    if (survival.IsNumber()) {
        skills.survival = std::stoi(survival.ToStdString());
    }
    else {
        wxLogError("Survival must be a number.");
    }
}
void Player::SetSwim(const wxString& swim) {
    if (swim.IsNumber()) {
        skills.swim = std::stoi(swim.ToStdString());
    }
    else {
        wxLogError("Swim must be a number.");
    }
}
void Player::SetThrowing(const wxString& throwing) {
    if (throwing.IsNumber()) {
        skills.throwing = std::stoi(throwing.ToStdString());
    }
    else {
        wxLogError("Throwing must be a number.");
    }
}
void Player::SetTrack(const wxString& track) {
    if (track.IsNumber()) {
        skills.track = std::stoi(track.ToStdString());
    }
    else {
        wxLogError("Track must be a number.");
    }
}

void Player::SetCharm(const wxString &charm) {
    if (charm.IsNumber()) {
        skills.charm = std::stoi(charm.ToStdString());
    }
    else {
        wxLogError("Charm must be a number.");
    }
}

void Player::SetNavigate(const wxString &navigate) {
    if (navigate.IsNumber()) {
        skills.navigate = std::stoi(navigate.ToStdString());
    }
    else {
        wxLogError("Navigate must be a number.");
    }
}



