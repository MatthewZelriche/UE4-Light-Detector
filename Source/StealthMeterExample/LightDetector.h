#pragma once

#include <memory>

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/TextureRenderTarget2D.h"
#include "UnrealClient.h"
#include "LightDetector.generated.h"

UCLASS()
class STEALTHMETEREXAMPLE_API ALightDetector : public AActor
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "LightDetection")
	float CalculateBrightness();

	void ProcessRenderTexture(UTextureRenderTarget2D *texture);

	TArray<FColor> pixelStorage;
	float pixelChannelR{ 0 };
	float pixelChannelG{ 0 };
	float pixelChannelB{ 0 };
	float brightnessOutput{ 0 };
	float currentPixelBrightness{ 0 };
	FRenderTarget *fRenderTarget;

	// The Render Textures we will be passing into the CalculateBrightness() method
	UPROPERTY(EditAnywhere)
	UTextureRenderTarget2D *detectorTextureTop;
	UPROPERTY(EditAnywhere)
	UTextureRenderTarget2D *detectorTextureBottom;

public:	
	// Sets default values for this actor's properties
	ALightDetector();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
