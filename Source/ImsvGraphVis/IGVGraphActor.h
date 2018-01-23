// Copyright 2017 Oh-Hyun Kwon. All Rights Reserved.

// UE4 see: https://docs.unrealengine.com/latest/INT/Programming/UnrealArchitecture/Reference/Classes/

// C++ include only once
#pragma once

// UE4 header files
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

// Graph element header files
#include "IGVCluster.h"
#include "IGVEdge.h"
#include "IGVProjection.h"

// UE4 requirement "At the top of each gameplay class header file, the generated header file (created automatically) needs to be included"
#include "IGVGraphActor.generated.h"

// UE4 "These are used to create the UClass for the class being declared, which can be thought of as the engine's specialized representation of the class"
// UE4 IMSVGRAPHVIS_API https://answers.unrealengine.com/questions/95747/why-does-adding-code-from-ue4-editor-add-this-api.html
UCLASS()
class IMSVGRAPHVIS_API AIGVGraphActor : public AActor
{
	GENERATED_BODY() // UE4 element

// UE4	EditDefaultsOnly - Indicates that this property can be edited by property windows, but only on archetypes. This operator is incompatible with the "Visible" tags
//		Category = TopCategory|SubCategory|... - Specifies the category of the property when displayed in Blueprint editing tools. Define nested categories using the | operator.
//		BlueprintReadWrite - This property can be read or written from a Blueprint. This operator is incompatible with the BlueprintReadOnly specifier.
//		TSubclassOf - https://answers.unrealengine.com/questions/462096/why-use-tsubclassof-and-not-just-the-class-itself.html

public:
	UPROPERTY(EditDefaultsOnly, Category = ImmersiveGraphVisualization)
	FString Filename;

	UPROPERTY(EditDefaultsOnly, Category = ImmersiveGraphVisualization)
	TSubclassOf<class AIGVNodeActor> NodeActorClass;

	UPROPERTY(VisibleAnywhere, Category = ImmersiveGraphVisualization)
	class USphereComponent* SphereComponent;

	UPROPERTY(VisibleAnywhere, Category = ImmersiveGraphVisualization)
	class UPostProcessComponent* PostProcessComponent;

	UPROPERTY(VisibleAnywhere, Category = ImmersiveGraphVisualization)
	class USkyLightComponent* SkyLightComponent;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = ImmersiveGraphVisualization)
	class UIGVEdgeMeshComponent* DefaultEdgeGroupMeshComponent;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = ImmersiveGraphVisualization)
	class UIGVEdgeMeshComponent* HighlightedEdgeGroupMeshComponent;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = ImmersiveGraphVisualization)
	class UIGVEdgeMeshComponent* RemainedEdgeGroupMeshComponent;

	UPROPERTY()
	class UMaterialInstanceDynamic* OutlineMaterialInstance;

// Interp - Indicates that the value can be driven over time by a Track in Matinee.
// EditAnywhere - Indicates that this property can be edited by property windows, on archetypes and instances.
// SaveGame - This specifier is a simple way to include fields explicitly for a checkpoint/save system at the property level. The flag should be set on all fields that are intended to be part of a saved game, and then a proxy archiver can be used to read/write it.

public:
	TArray<class AIGVNodeActor*> Nodes;
	TArray<FIGVEdge> Edges;
	TArray<FIGVCluster> Clusters;
	FIGVCluster* RootCluster;

	FVector2D PlanarExtent;

	UPROPERTY(Interp, EditAnywhere, BlueprintReadWrite, SaveGame,
			  Category = ImmersiveGraphVisualization,
			  meta = (UIMin = "1.0", UIMax = "360", ClampMin = "1", ClampMax = "360.0"))
	float FieldOfView;

	UPROPERTY(Interp, EditAnywhere, BlueprintReadWrite, SaveGame,
			  Category = ImmersiveGraphVisualization,
			  meta = (UIMin = "0.01", UIMax = "100", ClampMin = "0.01", ClampMax = "100.0"))
	float AspectRatio;  // for Treemap layout

	UPROPERTY(Interp, EditAnywhere, BlueprintReadWrite, SaveGame,
			  Category = ImmersiveGraphVisualization)
	EIGVProjection ProjectionMode;

	UPROPERTY(Interp, EditAnywhere, BlueprintReadWrite, SaveGame,
			  Category = ImmersiveGraphVisualization)
	float ClusterLevelScale;

	UPROPERTY(Interp, EditAnywhere, BlueprintReadWrite, SaveGame,
			  Category = ImmersiveGraphVisualization)
	float ClusterLevelExponent;

	UPROPERTY(Interp, EditAnywhere, BlueprintReadWrite, SaveGame,
			  Category = ImmersiveGraphVisualization)
	float ClusterLevelOffset;

	UPROPERTY(Interp, EditAnywhere, BlueprintReadWrite, SaveGame,
			  Category = ImmersiveGraphVisualization)
	float TreemapNesting;

	UPROPERTY(Interp, EditAnywhere, BlueprintReadWrite, SaveGame,
			  Category = ImmersiveGraphVisualization)
	int32 EdgeSplineResolution;

	UPROPERTY(Interp, EditAnywhere, BlueprintReadWrite, SaveGame,
			  Category = ImmersiveGraphVisualization)
	float EdgeWidth;

	UPROPERTY(Interp, EditAnywhere, BlueprintReadWrite, SaveGame,
			  Category = ImmersiveGraphVisualization,
			  meta = (ClampMin = "2", ClampMax = "32", UIMin = "2", UIMax = "32"))
	int32 EdgeNumSides;

	UPROPERTY(Interp, EditAnywhere, BlueprintReadWrite, SaveGame,
			  Category = ImmersiveGraphVisualization)
	float EdgeBundlingStrength;

	UPROPERTY(Interp, EditAnywhere, BlueprintReadWrite, SaveGame,
			  Category = ImmersiveGraphVisualization)
	float ColorHueMin;

	UPROPERTY(Interp, EditAnywhere, BlueprintReadWrite, SaveGame,
			  Category = ImmersiveGraphVisualization)
	float ColorHueMax;

	UPROPERTY(Interp, EditAnywhere, BlueprintReadWrite, SaveGame,
			  Category = ImmersiveGraphVisualization)
	float ColorHueOffset;

	UPROPERTY(Interp, EditAnywhere, BlueprintReadWrite, SaveGame,
			  Category = ImmersiveGraphVisualization)
	float ColorChroma;

	UPROPERTY(Interp, EditAnywhere, BlueprintReadWrite, SaveGame,
			  Category = ImmersiveGraphVisualization)
	float ColorLuminance;

	TArray<class AIGVNodeActor*> PickRayDistSortedNodes;
	class AIGVNodeActor* LastNearestNode;
	class AIGVNodeActor* LastPickedNode;

	UPROPERTY(Interp, EditAnywhere, BlueprintReadWrite, SaveGame,
			  Category = ImmersiveGraphVisualization)
	float PickDistanceThreshold;

	UPROPERTY(Interp, EditAnywhere, BlueprintReadWrite, SaveGame, Category = ImmersiveGraph)
	float DefaultLevelScale;

	UPROPERTY(Interp, EditAnywhere, BlueprintReadWrite, SaveGame, Category = ImmersiveGraph)
	float HighlightedLevelScale;

	UPROPERTY(Interp, EditAnywhere, BlueprintReadWrite, SaveGame, Category = ImmersiveGraph)
	float NeighborHighlightedLevelScale;

	FGraphEventArray EdgeUpdateTasks;
	bool bUpdateDefaultEdgeMeshRequired;

public:
	AIGVGraphActor();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = ImmersiveGraphVisualization)
	void EmptyGraph();

	UFUNCTION(BlueprintCallable, Category = ImmersiveGraphVisualization)
	void SetupGraph();

	UFUNCTION(BlueprintCallable, Category = ImmersiveGraphVisualization)
	float GetSphereRadius() const;

	UFUNCTION(BlueprintCallable, Category = ImmersiveGraphVisualization)
	void SetSphereRadius(float Radius);

	UFUNCTION(BlueprintCallable, Category = ImmersiveGraphVisualization)
	FVector Project(FVector2D const& P) const;

	UFUNCTION(BlueprintCallable, Category = ImmersiveGraphVisualization)
	void UpdatePlanarExtent();

	UFUNCTION(BlueprintCallable, Category = ImmersiveGraphVisualization)
	void NormalizeNodePosition();

	UFUNCTION(BlueprintCallable, Category = ImmersiveGraphVisualization)
	void UpdateTreemapLayout();

	UFUNCTION(BlueprintCallable, Category = ImmersiveGraphVisualization)
	void OnLeftMouseButtonReleased();

	UFUNCTION(BlueprintCallable, Category = ImmersiveGraphVisualization)
	void SetHalo(bool const bValue);

protected:
	void SetupNodes();
	void SetupEdges();
	void SetupClusters();

	void SetupEdgeMeshes();
	void UpdateEdgeMeshes();

	void UpdateColors();

	void ResetAmbientOcclusion();

	void UpdateInteraction();
	void UpdateNodeDistanceToPickRay();
};
