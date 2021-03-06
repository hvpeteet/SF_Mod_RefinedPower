// ILikeBanas

#pragma once

#include "CoreMinimal.h"
#include "ModularPower/RPMPBuilding.h"
#include "RPMPCoolingBuilding.generated.h"

/**
 * 
 */
UCLASS()
class REFINEDPOWER_API ARPMPCoolingBuilding : public ARPMPBuilding
{
    GENERATED_BODY()
public:
    ARPMPCoolingBuilding();

    virtual void BeginPlay() override;
    virtual void Factory_Tick(float dt) override;
    virtual void Tick(float dt) override;

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    void CacheConnections();

    void CollectItems(float dt);

    bool CanEjectGas();

    void EjectGas();


    int getGasItemCount();

    // Fluid Buffer

    virtual bool CanTransferToFluidBuffer() override;

    virtual void TransferToFluidBuffer() override;

    virtual bool CheckMPBuildingRunningState() override;


protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "RefinedPower")
    TSubclassOf<UFGItemDescriptor> mInputItemClass;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "RefinedPower")
    int mInputPullAmount = 200;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, Category = "RefinedPower")
    float mGasConsumpionRate = 0.0f;

    UFGPipeConnectionComponent* InputPipe;

    int mInputInvIndex = 0;
};
